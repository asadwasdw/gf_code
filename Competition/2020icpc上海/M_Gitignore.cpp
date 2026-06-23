#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n, m;cin >> n >> m;

    map<string, int> mp;
    int idx = 0;

    vector<vector<pair<int, int>>> g(5005);

    for (int i = 0; i < n; i++) {
        string s, t;cin >> s;
        int last = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '/') {
                if (!mp[t]) {
                    mp[t] = ++idx;
                    g[last].push_back({idx, 0}); 
                }
                last = mp[t];
            }
            t.push_back(s[j]);
        }
        if (!mp[s]) {
            mp[s] = ++idx;
            g[last].push_back({idx, 0}); 
        }
    }
    vector<int> vis(5005);
    for (int i = 0; i < m; i++) {
        string s, t;cin >> s;
        
        int last = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '/') {
                if (!mp[t]) {
                    
                    mp[t] = ++idx;
                    g[last].push_back({idx, 1}); 
                }
                last = mp[t];
                // cout << t << ' ' << mp[t] << '\n';    
            }
            
            t.push_back(s[j]);
        }
        if (!mp[s]) {
            mp[s] = ++idx;
            g[last].push_back({idx, 1}); 
        }
        vis[mp[s]] = true;
    }
   
    vector<int> cnt(5005);
    auto dfs = [&](auto self, int u) ->void {
        
        for (auto [v, w] : g[u]) {
            self(self, v);
            cnt[u] += w + cnt[v];
            // cout << u << ' ' << v << ' ' << w << '\n';
        }
    };

    auto calc = [&](auto self, int u) ->int {
        if (vis[u]) return 0;
        if (!cnt[u] && u || g[u].size() == 0) return 1;
        // cout << u << ' ' << cnt[u] << '\n';
        int res = 0;
        for (auto [v, w] : g[u]) {
            res += self(self, v);
        }
        
        return res;
    };


    dfs(dfs, 0);

    cout << calc(calc, 0) << '\n';

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}