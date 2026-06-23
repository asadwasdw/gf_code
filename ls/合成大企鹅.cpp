#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N];
double dp[N][N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int len = 1; len <= n; len ++) {
        for(int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                dp[l][r] = a[l];
            }

            for(int k = l; k + 1 <= r; k ++) {
                dp[l][r] = max(sqrt(dp[l][k] * dp[k + 1][r]), dp[l][r]);
            }
        }
    }

    cout << dp[1][n] << endl;








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