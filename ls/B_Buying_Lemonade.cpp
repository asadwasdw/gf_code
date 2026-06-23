#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n" 


void solve()
{
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1, 0);
    for(int i = 1; i <= n; i ++)  cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll ans = 0;

    for(int i = 1; i <= n; i ++) {
        ll w = 1ll * (a[i] - a[i - 1]) * (n - i + 1);
        if(k <= w) {
            ans += k + (i != 1);
            break;
        } else {
            ans += w + (i != 1);
            k -= w;
        }
    }
    cout << ans << endl;
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