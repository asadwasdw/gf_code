#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);


void solve()
{

    ll n; cin >> n;
    
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll t = i;
            if ((t - 1) % 2 == 0) {
                ll k = (t - 1) / 2;
                if (k != 0) {
                    ll x = n * k / (2 * k + 1) * 2;
                    if (x >= 1 && x < n) res.push_back(x);
                }
            }
            if (i * i != n) {
                t = n / i;
                if ((t - 1) % 2 == 0) {
                    ll k = (t - 1) / 2;
                    if (k != 0) {
                        ll x = n * k / (2 * k + 1) * 2;
                        if (x >= 1 && x < n) res.push_back(x);
                    }
                }
            }
        }
    }

    sort(res.begin(), res.end());
    
    cout << res.size() << '\n';
    for (auto x : res) cout << x << ' ';
    cout << '\n';




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