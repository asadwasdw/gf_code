#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ddddd(n + 1);
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ddddd[u] ++;
        ddddd[v] ++;
    }
    if(n == 1){
        cout << 1 << endl;return;
    }

    vector<PII> E;
    vector<bool> st(n + 1, 0);
    vector<int> d(n + 1, 0);

    auto bfs = [&](int s, int TTT) -> int {
        queue<int> q;
        q.push(s);
        d[s] = 1;
        int ans = s;

        vector<int> V;

        while(q.size()) {
            int u = q.front(); q.pop();
            V.push_back(u);
            st[u] = 1;
            // if(s == 5)cout << u << endl;
            for(auto v : adj[u]) {
                if(d[v]) continue;
                q.push(v);
                d[v] = d[u] + 1;
                if(d[ans] < d[v]) ans = v;
            }
        }

        if(!TTT) for(auto v: V) d[v] = 0;
        return ans;
    };



    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        cnt = max((int)adj[i].size(), cnt);
        // cout << adj[i].size() << endl;
        if(st[i]) continue;
        int p = bfs(i, 0);
        int q = bfs(p, 0);
        E.push_back({p, q});
        // cout << p << " " << q << endl;
    }
    // cout << cnt << endl;
    if(cnt == n - 1) {
        cout << "-1\n";
        return;
    }

    if(n == 2){
        if(m)cout << -1 << endl;
        else cout << 1 << ' ' << 2 << endl;
        return;
    }

    for(int i = 1; i < E.size(); i ++) {
        int u = E[i - 1].second;
        int v = E[i].first;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    int p = E[0].first;
    int q = bfs(p, 1);
    // cout << p << " " << q << endl;

    vector<vector<int>> ds(n + 1);
    vector<int> v[2];
    int zj = 0;
    for(int i = 1; i <= n; i ++) {
        ds[d[i]].push_back(i);
        zj = max(d[i], zj);
    }

    // cout << zj << endl;
    // for(int i = 1; i <= n; i ++) cout << d[i] << " \n"[i == n];

    if(n == 3) {
        vector<int>ans;
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(3);
        sort(ans.begin(), ans.end(), [&](int a, int b){
            return ddddd[a] < ddddd[b]; 
        });
        swap(ans[1], ans[0]);
    
        for(auto t:ans) cout << t << " ";
        cout << endl;
        return;
    }
    

    for(int i = 1; i <= zj; i ++) {
        for(auto t : ds[i]) {
            v[i%2].push_back(t);
        }
    }

    for(int i = 0; i < 2; i ++) {
        for(auto t : v[i ]) cout << t << " ";
    }
    cout << endl;
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