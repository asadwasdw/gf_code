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

ll dp1[50][100010];
ll dp2[50][100010];

void solve()
{
    ll n;
    cin >> n;
    vector<ll> lsh;
    for(ll i = 1; i * i <= n; i ++) {
        if(n % i == 0) {
            lsh.push_back(i);
            lsh.push_back(n / i);
        }
    }
    lsh.push_back(0);
    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
    int m = lsh.size() - 1;
    dp1[0][0] = 1;
    for(int i = 1; i <= m; i ++) {
        for(int j = m; j >= 1; j --) {
            if(dp1[i][j] == 0) continue;
            for(int ni = i + 1; ni <= m; ni ++) {
                if(lsh[j] * lsh[ni] > n) continue;
                int nj = lower_bound(lsh.begin(), lsh.end(), lsh[j] * lsh[ni]) - lsh.begin();
                dp1[i + 1][nj] += dp1[i][j];
                dp2[i +][nj] += dp2[i][j] + lsh[ni] * dp1[i][j];
            }
        }
    }

    for(int i = 1; i <= m; i ++) {
        ans += dp2[i][m] * fac[i];
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
    return 0;
}