#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);

int id[N][2], now;

void add(int a, int b) {
    // cout << a << " " << b << endl;
    edg[a].push_back(b);
}

int dfn[N], low[N], tim, sccno[N], scc_cnt;
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++ tim;
    stk.push(u);
    for(auto v : edg[u]) {
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

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        id[i][0] = ++ now;
        id[i][1] = ++ now;
    }
    for(int k = 1; k <= m; k ++) {
        int i, a, j, b;
        cin >> i >> a >> j >> b;
        int fa = a ^ 1, fb = b ^ 1;
        add(id[i][fa], id[j][b]);
        add(id[j][fb], id[i][a]);
    }

    Tarjan(now);
    assert(now == 2 * n);

    for(int i = 1; i <= n; i ++) {
        if(sccno[id[i][0]] == sccno[id[i][1]]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

   cout << "POSSIBLE\n";

    for(int i = 1; i <= n; i ++) {
        if(sccno[id[i][0]] < sccno[id[i][1]]) cout << "0 ";
        else cout << "1 ";
    }
}


signed main()
{
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