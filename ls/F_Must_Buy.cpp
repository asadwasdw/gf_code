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



void solve()
{
    int n, m;
    cin >> n >> m;
    vector dp1(n + 5, vector(m + 5, 0ll));
    vector dp2(n + 5, vector(m + 5, 0ll));

    vector p(n + 1, 0ll), v(n + 1, 0ll);
    for(int i = 1; i <= n; i ++) {
        cin >> p[i] >> v[i];
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            if(j >= p[i]) dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - p[i]] + v[i]);
            else dp1[i][j] = dp1[i - 1][j];
        }
    }

    for(int i = n; i >= 1; i --) {
        for(int j = 0; j <= m; j ++) {
            if(j >= p[i]) dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - p[i]] + v[i]);
            else dp2[i][j] = dp2[i + 1][j];
        }
    }

    ll res = dp1[n][m];
    // cout << dp1[n][m] << " " << dp2[1][m] << endl;

    vector ans(n + 1, 'B');

    for(int i = 1; i <= n; i ++) {
        {
            ll mx = -1;
            for(int l = 0; l <= m; l ++) {
                int r = m - l;
                mx = max(mx, dp1[i - 1][l] + dp2[i + 1][r]);
            }

            if(mx < res) ans[i] = 'A';
        }

        {
            ll mx = -1;
            for(int l = 0; l <= m - p[i]; l ++) {
                int r = m - p[i] - l;
                mx = max(mx, dp1[i - 1][l] + dp2[i + 1][r]);
            }

            if(mx + v[i] < res) ans[i] = 'C';
        }
    }


    for(int i = 1; i <= n; i ++) cout << ans[i];

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