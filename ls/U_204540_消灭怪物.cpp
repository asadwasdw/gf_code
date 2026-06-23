#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define l first
#define r second

//vector<vector<int>>adj(N);

ll a[N], d[N];
ll b[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];

    }
    
    for(int i = 1; i <= m; i ++ ) {
        ll l, r;
        cin >> l >> r;
        b[l] = max(b[l], r);
    }

    for(int i = 1; i <= n; i ++) {
        b[i] = max(b[i], b[i - 1]);
        // cout << i << " " << b[i] << endl;
    }

    ll ans = 0, now = 0;
    for(int i = 1; i <= n; i ++ ) {
        now += d[i];
        if(now < a[i]) {
            ll t = a[i] - now;
            d[i] += t;
            d[b[i] + 1] -= t;
            now += t;
            ans += t;
        }
    }
    cout << ans;
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