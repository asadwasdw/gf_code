#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{

    ll n, k, m, c, d;
    cin >> n >> k >> m >> c >> d;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll l = 0, r = 1e18, res = 0;

    auto check = [&] (ll val) -> bool {
        vector<ll> sum(n + 2);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= val) cnt++;
            else {
                if (d) {
                    ll x = max((val - a[i] - c + d - 1) / d, 0ll);
                    // cout << x << '\n';
                    if (x < m) {
                        int l = max(1ll, i - m + 1);
                        int r = i - x;
                        if (r <= 0) continue;
                        // cout << i << ' ' << l << ' ' << r << '\n';
                        
                        sum[l]++;
                        sum[r + 1]--;
                    }
                }else {
                    if (a[i] + c >= val) {
                        sum[max(1ll, i - m + 1)]++;
                        sum[i + 1]--;
                    }
                }
                
            }
        }
        ll mx = 0;
        for (int i = 1; i <= n - m+1; i++) {
            sum[i] += sum[i - 1];
            mx = max(mx, sum[i]);
        }
        return mx + cnt >= k;
    };
    // cout << check(4) << ' ';
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (check(m)) l = m + 1, res = m;
        else r = m - 1; 
    }
    cout << res << '\n';





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