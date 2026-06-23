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


ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

void solve()
{
    // (n - b + 1) - (n/b)

    ll n;
    cin >> n;

    ll ans1 = ((n + 1) % mod) * (n % mod) % mod * qmi(2, mod - 2, mod) % mod;
    ll ans2 = 0;

    for(ll l = 1; l <= n; l ++) {
        ll r = n / (n / l);

        ans2 += (r - l + 1) % mod * (n / l) % mod;
        ans2 %= mod;

        l = r;
    }


    // cout << ans1 << " " << ans2 << endl;

    cout << (ans1 - ans2 + mod) % mod << endl;
    









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