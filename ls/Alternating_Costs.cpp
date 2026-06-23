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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    x = abs(x), y = abs(y);
    ll ans = 0;

    ll t = min(x, y);
    x -= t, y -= t;
    ans += t * min(a, b) * 2;

    if(x) {
        ll cnt1 = (x + 1) / 2, cnt2 = x - cnt1;
        ll res1 = cnt1 * 3 * b + cnt2 * b;
        ll res2 = cnt1 * a + cnt2 * 3 * a;
        ll res = cnt1 * a + cnt2 * b;

        ans += min({res1, res2, res});
    } else {
        swap(a, b);
        swap(x, y);

        ll cnt1 = (x + 1) / 2, cnt2 = x - cnt1;
        ll res1 = cnt1 * 3 * b + cnt2 * b;
        ll res2 = cnt1 * a + cnt2 * 3 * a;
        ll res = cnt1 * a + cnt2 * b;

        ans += min({res1, res2, res});
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
    return 0;
}