#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 



typedef pair<vector<int>, int> pvi;


void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>>adj(n + 1);

    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<pvi,vector<pvi>,greater<pvi>> q;
    vector<int> t;t.push_back(x);
    q.push({t, x});

    unordered_map<int,int> st2;

    while(q.size()) {
        auto [t, u] = q.top();q.pop();

        if(st2[u]) continue;
        st2[u] = true;


        if(u == y) {
            for(auto T : t) cout << T << " "; cout << endl;
            break;
        }
        unordered_map<int,int> st;
        for(auto T : t) st[T] = 1;
        for(auto v : adj[u]) {
            if(st.count(v)) continue;
            if(st2.count(v)) continue;
            t.push_back(v);
            q.push({t, v});
            t.pop_back();
        }
    }
    







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}