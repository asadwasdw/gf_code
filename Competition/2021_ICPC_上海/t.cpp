#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 7;

struct Edge {
    int from, to, dis;
}e[maxN], initEdge[maxN];

int n, m, q, head[maxN], cnt, tot, fa[maxN], f[maxN][23];
long long sum[maxN], maxNum[maxN][23], val[maxN];
/*
sum[x]记录的是在子树x xx上能获得的能力值
m a x N u m [ x ] [ i ] maxNum[x][i]maxNum[x][i]记录的是从x xx到它的i ii级祖先中,最大的边权比能够获得的能力值大多少
*/
inline void add(int u, int v, int w = 0)
{
    e[++cnt].from = head[u];
    e[cnt].to = v;
    e[cnt].dis = w;
    head[u] = cnt;
}

bool cmp(Edge x, Edge y)
{
    return x.dis < y.dis;
}

int Find(int x)
{
    return fa[x] == x? x : fa[x] = Find(fa[x]);
}

inline void KruskalTree() //Kruskal重构树
{
    sort(initEdge + 1, initEdge + 1 + m, cmp);
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
    tot = n;    
    for(int i = 1; i <= m; ++i) {
        if(tot == (n << 1) - 1)
            break;
        int fx = Find(initEdge[i].from), fy = Find(initEdge[i].to);
        if(fx == fy)
            continue;
        val[++tot] = initEdge[i].dis;
        fa[tot] = fa[fx] = fa[fy] = tot;
        add(tot, fx); add(tot, fy);
    }    
}

void dfs1(int x) //记录祖先,计算sum数组
{
    if(x <= n) {
        sum[x] = val[x];
        return ;
    }
    for(int i = head[x]; i; i = e[i].from) {
        int y = e[i].to;
        f[y][0] = x; 
        dfs1(y);
        sum[x] += sum[y];
    }
}

void dfs2(int x) //更新maxNum
{
    maxNum[x][0] = val[f[x][0]] - sum[x];
    for(int i = 1; i <= 19; ++i) {
        f[x][i] = f[f[x][i - 1]][i - 1];
        maxNum[x][i] = max(maxNum[x][i - 1], maxNum[f[x][i - 1]][i - 1]);
    }
    for(int i = head[x]; i; i = e[i].from) {
        int y = e[i].to;
        dfs2(y);
    }
}

inline int query(int x, int k) //倍增求结果
{
    for(int i = 19; i >= 0; --i)
        if(f[x][i] && maxNum[x][i] <= k)
            x = f[x][i];
    return sum[x];        
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) 
        scanf("%lld", &val[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d%d%d", &initEdge[i].from, &initEdge[i].to, &initEdge[i].dis);    
    KruskalTree();
    dfs1(tot); dfs2(tot); //注意,tot节点是新树的根节点
    for(int i = 1; i <= q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", y + query(x, y));
    }
    return 0;
}
