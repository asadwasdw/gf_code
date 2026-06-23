#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=510+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int c[N][N];

void init() {
    c[0][0] = 1;
    c[1][1] = 1;
    c[1][0] = 1;
    for(int i = 2; i <= 500; i ++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j ++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int a[N];
int sum[N];
int dp[N][N];

void solve()
{
    init();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i], sum[i] = sum[i - 1] + a[i];

    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++) cout << sum[i] << " \n"[i == n];

    // for(int i = 0; i <= n; i ++) {
    //     for(int j = 0; j <= i; j ++) cout << c[i][j] << " \n"[j == i];
    // }

    dp[0][0] = 1;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= sum[i]; j ++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            //全放在后面

            // 枚举新的位置
            for(int k = j + 1; k <= sum[i + 1]; k ++) {

                
                // 枚举放在后面的数量x
                int l = max(0ll, a[i + 1] - (k - j));
                // 不放在后面的，最多只能放(k-j)个,超过就会使（新的最后一个长度为 2 的下降子序列靠前的那个数字的位置)>k
                // 那么放在后面的，最少就是（a[i + 1] - (k - j)）

                int r = min(a[i + 1] - 1, sum[i + 1] - k - 1);
                // 至少留一个去更新, 放在k
                // (k + 1 + x <= sum[i - 1]) => (x <= sum[i - 1] - k - 1) 后面的数量不能过多，放在长度会超过sum[i - 1]

                for(int x = l; x <= r; x ++) {
                    dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * c[k - j - 1][a[i + 1] - x - 1]) % mod;

                     // （j - k] 有(k - j)个位置，第k个位置一定要是（i + 1） 还有[k - j - 1]个位置要放[a[i] + 1 - x - 1]个(i + 1) 
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= sum[n]; i ++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans;

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