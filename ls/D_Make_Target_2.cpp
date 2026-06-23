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

ll ans = 0;


ll get(ll x) {
    if(x < 0)return 0;
    return x/2 +1;
}

ll calc(ll l, ll r) {
    if(l > r) return 0;

    if(l >= 0) return get(r) - get(l - 1);
    if(r <= 0) return get(-l) - get(-r - 1);

    return get(r) + get(-l) - 1;
}

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;

    for(int i = l; i <= r; i ++) {
        int x = abs(i);

        int lx = max(-x, d);
        int rx = min(x, u);

        if(lx <= rx && x % 2 == 0) {
            ans += rx - lx + 1;
        }

        ans += calc(max(x + 1, d), u);
        ans += calc(d, min( -x - 1, u));
    }

    cout << ans << endl;




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