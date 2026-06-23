#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 





void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    vector<vector<int>>adj(n + 1);
    vector<vector<int>> dp(2 * k + 1, vector<int>(n + 1, 0));
    
    cin >> s;
    s = " " + s;

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int u = 1; u <= n; u ++) {
        if(s[u] == 'A') dp[0][u] = 1;
        else dp[0][u] = 0;
    }


    for(int i = 1; i <= 2 * k; i ++) {
        for(int u = 1; u <= n; u ++) {
            if(i % 2 == 0) {
                for(auto v : adj[u]) if(dp[i - 1][v] == 1) dp[i][u] = 1;
            } else {
                dp[i][u] = 1;
                for(auto v : adj[u]) if(dp[i - 1][v] == 0) dp[i][u] = 0;
            }

            // if(i%2==0) // Alice 会选任意一个自己必胜的局面走
            //     dp[i][u] = any_of(adj[u].begin(), adj[u].end(), [&](int v) { return dp[i-1][v]==true; });
            // else // Bob 会选任意一个 Alice 必败的局面走
            //     dp[i][u] = all_of(adj[u].begin(), adj[u].end(), [&](int v) { return dp[i-1][v]==true; });
        }
    }

    if(dp[2 * k][1] == 1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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