#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);

int sccnt;
int low[N], num[N], dfn;
int sccno[N];
stack<int> sta;

void dfs(int u) {
    sta.push(u);
    low[u] = num[u] = ++ dfn;

    for(auto v : adj[u]) {
        if(!num[v]) {
            dfs(v);
            low[u] = min(low[v], low[u]);
        } else if (!sccno[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if(low[u] == num[u]) {
        sccnt ++;
        while(1) {
            int v = sta.top(); sta.pop();
            sccno[v] = sccnt;
            if(u == v) break;
        }
    }
}


void solve()
{







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