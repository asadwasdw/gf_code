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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 10, 0);
    vector<ll> s(n + 10, 0);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    // for(int i = n; i >= 1; i --) {
    //     s[i] = s[i + 1] + a[i];
    // }

    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        ll t = x - (s[n] - s[i - 1]);
        ans += max(0ll, (ll)(k - (t + s[n] - 1) / s[n]));
        // cout <<  (x + s[n] - 1)/s[n] << " " << ans << endl;
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