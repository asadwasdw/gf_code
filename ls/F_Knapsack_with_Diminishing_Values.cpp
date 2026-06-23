#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<ll>>adj(N);


void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        ll v, w; cin >> v >> w;
        for(int j = 1; j * v <= m; j ++) {
            adj[v].push_back(w - 2 * j  + 1);
        }
    }
    vector<ll> dp(m + 1, 0);
    for(int i = 1; i <= m; i ++) {
        sort(adj[i].begin(), adj[i].end(),[&](int a, int b){
            return a > b;
        });// 保证取k个时， 一定会先取到 k-1 
        for(int j = 0; j * i <= m && j < adj[i].size(); j ++) { // 调和级数
            for(int k = m; k >= i; k --) { // 01背包
                dp[k] = max(dp[k], dp[k - i] + adj[i][j]); 
            }            
        }
    }
    cout << dp[m] << endl;






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