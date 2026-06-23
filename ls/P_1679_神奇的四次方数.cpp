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

//vector<vector<int>>adj(N);

int dp[N];

void solve()
{
    int m;
    cin >> m;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i * i * i * i <= m; i ++) {
        int v = i * i * i * i, w = 1;
        for(int j = v; j <= m; j ++) {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }

    cout << dp[m];
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
    return 0;
}