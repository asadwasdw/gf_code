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
int x[N], y[N], t[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> t[i] >> x[i] >> y[i] ;
    }

    int ans = 0;

    for(int i = 1; i <= m; i ++) {
        dp[i] = 1;
        for(int j = 1; j < i; j ++) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= abs(t[i] - t[j])) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
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