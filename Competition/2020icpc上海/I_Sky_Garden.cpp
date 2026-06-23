#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef long double db;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
//vector<vector<int>>edg(N);


void solve()
{
    int n, m;cin >> n >> m;


    vector<db> dp(m + 1);
    db res = 0, sum = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            db dis = 2 * PI * i / (2 * m);
            dp[j] = min(dp[j] + 2, dis * j);
        } 

        res += (sum + 1) * 2 * m;
        for (int j = 1; j < m; j++) {
            sum += 2 * dp[j];
            res += 2 * m * dp[j];
        }
        sum += dp[m];
        sum += 2 * m * i + 1;
        
        res += m * dp[m];
    }

    if(m==1) {
        res -= n * (n+1);
    }



    cout << res << '\n';



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cout << setprecision(10) << fixed;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}