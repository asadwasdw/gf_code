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
    ll l, r, p, q;
    cin >> l >> r >> p >> q;


    auto calc = [&](ll n) {
        ll res = 0;
        ll cnt1 = n / q, cnt2 = n % q;

        // cout << cnt1 << " " << cnt2 << endl;
        if(cnt2 >= p) {
            res = (cnt1 + 1) * (0 + p - 1) * p / 2;
        }  else {
            res = cnt1 * (0 + p - 1) * p / 2 + (1 + cnt2) * cnt2 / 2;
        }
        return res;
    };

    // cout << calc(r) << endl;


    // cout << calc(l - 1) << " " << calc(r) << endl;

    cout << calc(r) - calc(l - 1) << endl;







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
    return 0;
}