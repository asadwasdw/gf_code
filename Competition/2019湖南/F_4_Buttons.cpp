#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    ll n, a, b, c, d;
    while(cin >> n >> a >> b >> c >> d) {
        __int128_t ans = 1;
        ans = (ans + n * ((a + b + c + d) % mod) % mod) % mod;
        ans = ans + __int128_t(1) * ((((a + c)%mod) * ((b + d)%mod))%mod * (((n) * (n - 1) / 2)%mod))%mod;
        ans %= mod;
        cout << (ll)ans << endl;
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