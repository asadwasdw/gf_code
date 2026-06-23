#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5000+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,k;
int a[N];
int dp[N][N];
string s;
int ans = 0;

bool pd(int x) {
    string t;
    for(int i = 0; i < k; i ++) {
        if(x % 2) t += '0';
        else t += '1';
        x /= 2;
    }
    string T = t;
    reverse(T.begin(),T.end());
    return t == T;
}


void solve()
{
    cin >> n >> k;

    cin >> s;
    s = " " + s;

    for(int i = 1; i <= n; i ++) {
        if(s[i] == '?') a[i] = -1;
        else a[i] = (int)(s[i] - 'A');
    }

    // for(int i = 1; i <= n; i ++) cout << a[i]; cout << endl;

    dp[0][0] = 1;
    int ST = (1 << k);

    for(int i = 1; i <= n; i ++) {
        for(int st = 0; st < ST; st ++) {

            int nst1 = (st << 1 | 1) % ST;
            int nst0 = (st << 1 | 0) % ST;
            if(i <= k) {
                if(a[i] == -1) {
                    dp[i][nst1] += dp[i - 1][st];
                    dp[i][nst0] += dp[i - 1][st];
                }
                else {
                    dp[i][(st << 1 | a[i]) % ST] += dp[i - 1][st];
                }

            }
            else {
                if(pd(st)) continue;

                if(a[i] != 0){
                    if(!pd(nst1)) {
                        dp[i][nst1] += dp[i - 1][st];
                    }
                }
                
                
                if(a[i] != 1){
                    if(!pd(nst0)) {
                        dp[i][nst0] += dp[i - 1][st];
                    }
                }
            }

            dp[i][nst1] %= mod;
            dp[i][nst0] %= mod;
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j < ST; j ++) cout << dp[i][j] << " \n"[j == ST - 1];
    // }

    for(int st = 0; st < ST; st ++) {
        if(pd(st)) continue;
        ans += dp[n][st];
        ans %= mod;
    }
    cout << ans % mod;

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