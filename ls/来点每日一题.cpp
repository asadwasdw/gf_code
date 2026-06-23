#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 100000;

ll dp[1100][10][2]; // 以a[j]结尾的最值
ll a[N];
ll f[1100][1100];
ll F[N];
void solve()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) for(int k = 0; k <= 6; k++) dp[j][k][0] = INFll, dp[j][k][1] = -INFll;

        for(int j = i; j <= n; j++) {
            for(int k = 1; k <= 6; k ++) {
                if(k == 1) {
                    dp[j][k][0] = min(dp[j-1][k][0],a[j]); 
                    dp[j][k][1] = max(dp[j-1][k][1],a[j]); 
                }
                else {


                    dp[j][k][0] = dp[j-1][k][0];
                    dp[j][k][1] = dp[j-1][k][1];

                    if(k % 2 == 0) {

                        if(dp[j-1][k-1][0] != INFll)dp[j][k][0] = min(dp[j-1][k][0], dp[j-1][k-1][0]-a[j]);
                        if(dp[j-1][k-1][1] != -INFll)dp[j][k][1] = max(dp[j-1][k][1], dp[j-1][k-1][1]-a[j]);
                        
                    } 
                    else {


                        if(dp[j-1][k-1][0] != INFll) {
                            dp[j][k][0] = min(dp[j][k][0],dp[j-1][k-1][0]*a[j]);
                            dp[j][k][1] = max(dp[j][k][1],dp[j-1][k-1][0]*a[j]);
                        }

                        if(dp[j-1][k-1][1] != -INFll) {
                            dp[j][k][0] = min(dp[j][k][0],dp[j-1][k-1][1]*a[j]);
                            dp[j][k][1] = max(dp[j][k][1],dp[j-1][k-1][1]*a[j]);
                        }

                    }
                }
                // cout<<dp[j][k][1]<<" ";
            }
            // cout<<endl;
             if(j>=i+5)f[i][j] = max(f[i][j],dp[j][6][1]);

            
        }
    }


    ll ans = 0;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<i;j++) {
            F[i] = max(F[i],F[j]+f[j+1][i]);
        }
        ans = max(ans,F[i]);
        // cout << F[i] << " " << i << endl;
    }

    cout << ans << endl;



    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n;j++) cout << f[i][j] <<" ";cout << endl;
    // }





}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}