#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10,M = N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


/*
使用说明
需要识别出闭合子图，
所谓闭合子图就是给定一个有向图，从中选择一些点组成一个点集V。对于V中任意一个点，其后续节点都仍然在V中
闭合子图（选择出点集，没有出去的有向边）
选择一个闭合子图， 这个权是最大的

举例    
制造一些物品，可以获得对应的利益，
同时在制作的过程中，需要花费一些代价去买需要的东西
那么物品到对应的所需物品就有一个边，如果我选择了这个物品，那就一定要选择所需物品，
这不仅仅是题目的要求，也是我选出的点集构成闭合子图的关键

注意点
1.所需物品应该是不会被消耗的，如果可以被消耗，那么直接将所需花费从获利中剪掉就行 
    （？）如果物品有消耗次数，制作某个物品只会被消耗一部分，没碰见过，不知道
2.所需物品是多个制作品可以共用的，（可以 ！= 必须）
    只服务单次制作的话，直接剪掉就好，理由同上


做法
转化为最小割，用最大流求解

1.原本所有的依赖关系全部保留，但是容量是INF
2.所有的制作获利， 将他们从S连边，容量是 本次获利
3.所有的依赖品 ， 全部连向T, 容量是 abs(消耗)
从源点s向每个正权点连一条容量为权值的边，每个负权点向汇点t连一条容量为权值的绝对值的边，有向图原来的边容量全部为无限大。

跑完后，ans = sum(正权) - 最小割

最优性
最小割=(不选的正权之和+要选的负权绝对值之和）
最大权闭合子图=（正权之和-不选的正权之和-要选的负权绝对值之和）=正权值和-最小割
因为正权值和，是定值，而最小割保证值最小，所以最大权闭合子图一定最优。

详细解释链接
https://blog.csdn.net/can919/article/details/77603353


本例题链接
https://codeforces.com/gym/104871/problem/C

*/

//vector<vector<int>>edg(N);
int n, m, S, T;
int a[N];
ll h[N], e[M], ne[M], f[M], idx;
int d[N], cur[N];


void add(int a, int b, int c) {
    // cout << a << " " << b << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    memset(d, -1, sizeof(int) * T * 4);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int find(int u, ll limit) {
    if(u == T) return limit;
    ll flow = 0;

    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;
        if(d[v] == d[u] + 1) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) cur[u] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

ll dinic() {
    ll ans = 0, flow;
    while(bfs())
        if(flow = find(S, INF))
            ans += flow;
    return ans;
}

void clear() {
    memset(h, -1, sizeof h);
    idx = 0;
}


int w[N];
int g[N],c[N],t[N];

PII edge[N];

int b[N], v[N];

void solve()
{
    int n, m, g;
    cin >> n >> m >> g;
    S = 0, T = n + m + 1;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        if(a[i] == 0) {
            add(S, i, v[i]);
        }
        else {
            add(i, T, v[i]);
        }
    }
    int sum = 0;
    for(int i = 1; i <= m; i ++) {
        int t,w,k;
        cin >> t >> w >> k;
         sum += w;
        while(k --) {
            int x; cin >> x;
            if(t == 1) add(x, n + i, INF);
            else add(i + n, x, INF);
        }
        int st; cin >> st;
        if(st) w += g;
        if(t == 1) add(n + i, T, w);
        else add(S, n + i, w);
       
    }
    cout << sum - dinic() << endl;
}


signed main()
{
    clear();   
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}