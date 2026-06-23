#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int h[N], ne[N],idx,e[N];
int id[N][2], now;

void add(int a, int b) {
    // cout << a << " " << b << endl;
    // edg[a].push_back(b);
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfn[N], low[N], tim, sccno[N], scc_cnt;
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++ tim;
    stk.push(u);
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!sccno[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(dfn[u] == low[u]) {
        ++ scc_cnt;
        while(1) {
            int v = stk.top(); stk.pop();
            sccno[v] = scc_cnt;
            if(u == v) break;
        }
    }
}

void Tarjan(int n) {
    for(int i = 1; i <= n; i ++) {
        if(!dfn[i]) tarjan(i);
    }
} 

/*

条件判断
1 a V b(至少有1个为true) <=> fa -> b, fb -> a
2 a b 不同时为true       <=> fa -> b, fb -> a
3 a 为 1   <=> a V a <=> fa -> a
*/

void solve()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++) {
        id[i][0] = ++ now;
        id[i][1] = ++ now;
    }
    for(int k = 1; k <= m; k ++) {
        int i, a, j, b;
        // cin >> i >> a >> j >> b;
        scanf("%d%d%d%d",&i,&a,&j,&b);
        int fa = a ^ 1, fb = b ^ 1;
        add(id[i][fa], id[j][b]);
        add(id[j][fb], id[i][a]);
    }

    Tarjan(now);
    // assert(now == 2 * n);

    for(int i = 1; i <= n; i ++) {
        if(sccno[id[i][0]] == sccno[id[i][1]]) {
          puts("IMPOSSIBLE");
            return;
        }
    }

    puts("POSSIBLE");

    for(int i = 1; i <= n; i ++) {
        if(sccno[id[i][0]] < sccno[id[i][1]]) printf("0 ");
        else printf("1 ");
    }
}


signed main()
{
    int t;t=1;
    memset(h, -1, sizeof h);
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}