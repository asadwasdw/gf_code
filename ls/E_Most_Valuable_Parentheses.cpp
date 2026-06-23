#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector a(n + 1, 0ll);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    multiset<ll> q1, q2;
    ll ans = 0;
    ll res = 0;
    for(int i = 1; i <= n; i ++) {
        if(q1.size() == q2.size()) { //左
            // q1.insert(a[i]);

            if(q2.size() &&  *q2.rbegin() > a[i]) { 
                int t = *q2.rbegin();
                q1.insert(t);
                q2.erase(prev(q2.end()));
                q2.insert(a[i]);
            } else {
                q1.insert(a[i]);
            }

        } else {
            
            q2.insert(a[i]);
            
        }
        // cout << i << " : ";
        // for(auto t : q1) {
        //     cout << t << " ";
        // }cout << endl;
    }

    for(auto t : q1) {
        ans += t;
    }

    cout << ans << endl;





    // vector dp(n + 10, vector(n + 10, -INFll));
    // dp[0][0] = 0;

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j <= i; j ++) {
    //         if(j)dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]); // 左
    //         dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);

    //         // cout << dp[i][j] << " \n"[j == i];
    //     }
    // }

    // cout << dp[n][0] << endl;







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