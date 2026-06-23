#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> u(m + 1), v(m + 1), c(m + 1);
    vector<int> deg(n + 1);
    vector<vector<int>> edg(n + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> u[i] >> v[i] >> c[i];
        // cout << u[i] << v[i] << endl;
        deg[u[i]] += c[i];        
        deg[v[i]] += c[i];
        edg[u[i]].push_back(i);        
        edg[v[i]].push_back(i);        
    }

    vector<bool> vis(n + 1);
    auto dfs = [&](auto self, int x) -> void {
        vis[x] = true;
        for(auto i : edg[x]) {
            int y = x ^ u[i] ^ v[i];
            if(vis[y]) continue;
            if(c[i]) continue;
            self(self,y);
            if(deg[y] % 2 == 1) {
                deg[x] += 1;
                deg[y] += 1;
                c[i] = 1;
            }
        }
    };

    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        dfs(dfs, i);
        if(deg[i] % 2 == 1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    vector<int> ans;
    auto eular = [&](auto self, int x) -> void {
        while(edg[x].size()) {
            int i = edg[x].back(); edg[x].pop_back();
            int y = x ^ u[i] ^ v[i];
            if(c[i] == 0) continue;
            c[i] = 0;
            self(self, y);
        }
        ans.push_back(x);
    };

    eular(eular,1);


    cout << ans.size() - 1 << endl;
    for(int i = 0; i < ans.size(); i ++) cout << ans[i] << " \n"[i == ans.size() - 1];

    // cout << "S\n";
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