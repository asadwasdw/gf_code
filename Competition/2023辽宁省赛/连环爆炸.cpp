#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int n; 
    cin >> n;
    vector<PII> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a.begin() + 1, a.begin() + n + 1,[&](PII A, PII B) {
        if(A.x == B.x) return A.y > B.y;
        return A.x < B.x;
    }); // 按照死亡顺序排序 

    vector dp(n + 1, vector (n + 1, INFll)); // 前i个，杀了j个，全死的最小初始伤害 
    dp[1][0] = a[1].x;
    dp[1][1] = 0;
    int sum = 0;
    for(int i = 2; i <= n; i ++) {
        sum += a[i - 1].y; 
        for(int j = 0; j <= i; j ++) {
            if(sum >= a[i].x) { // 前面死的所有怪可以崩死i
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            } else {            // 不可以直接崩死
                                // 设这种情况下需要的额外伤害是t
                                // 需要a[i].x - sum 的额外伤害
                                // 也要保证 t >= dp[i - 1][j], 这样初始伤害才够杀掉前i-1个， 
                dp[i][j] =  min(dp[i][j], max(dp[i - 1][j], a[i].x - sum));
            }
            if(j)dp[i][j] = min(dp[i][j], max(0ll,dp[i - 1][j - 1] - a[i].y));
            // 直接做掉 i;
            // 再杀掉前i-1个只需要 dp[i-1][j-1] - a[i].y 额外伤害
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j <= i; j ++) {
    //         cout << dp[i][j] << " \n"[j == i];
    //     }
    // }
    for(int j = 1; j <= n; j ++) {
        // cout << dp[n][j] << ' ';
        if(dp[n][j] == 0) {
            cout << j;
            return;
        }
    }






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