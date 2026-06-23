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

struct gfBIT {
    int n;
    vector<int> tr;

    void clear() {
        tr.clear();
        tr.resize(n, 0); 
    }

    void init(int _n) {
        n = _n + 10;
        clear();
    }

    int lowbit(int x) {
        return (x) & (-x);
    }

    void update(int x, int d) {
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += d;
    }

    ll sum(int x) {
        ll ans = 0;
        for(int i = x; i > 0; i -= lowbit(i)) ans += tr[i];
        return ans;
    }

    ll get(int l, int r) {
        return sum(r) - sum(max(0,l - 1));
    }

    void debug() {
        cout << n << endl;
        for(int i = 1; i <= n; i ++) {
            cout << get(i, i) << " \n"[i == n];
        }
    }
}bitl, bitm, bitr;
int a[N];

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    bitl.init(n), bitr.init(n), bitm.init(n);
    ll sum = 0;

    // for(int i = 1; i <= n; i ++) {
    //     sum += bitm.get(a[i], n);
    //     bitm.update(a[i], 1);
    // }

    // bitm.clear();
    // ll cnt = 0;
    // for(int i = 1; i <= k; i ++) {
    //     cnt += bitm.get(a[i], n);
    //     bitm.update(a[i], 1);
    // }
    for(int i = k + 1; i <= n; i ++) {
        sum += bitr.get(a[i], n) + bitm.get(a[i], n);
        bitr.update(a[i], 1);
    }



    ll ans = 0;

    for(ll l = 1, r = k; r <= n; l ++, r ++) {
        ans += k*(k-1)%mod * qmi(4, mod - 2) % mod;
        ans += (sum ) ;

        // cout << l << " " <<  r << " " << sum - cnt  << " "  << cnt <<  endl;

        if(r != n) {
            // bitm.update(a[l], -1);
            // cnt -= bitm.get(1, a[l]);
            // cnt += bitm.get(a[r + 1], n);
            // bitm.update(a[r + 1], 1);


            sum -= bitl.get(a[r + 1], n) + bitm.get(a[r + 1], n);
            sum -= bitl.get(a[l], n);
            bitl.update(a[l], 1);
            bitm.update(a[l], -1);

            bitm.update(a[r + 1], 1);
            bitr.update(a[r + 1], -1);

            sum += bitl.get(a[l] + 1, n) ;

            // cout << 1 << " - " << a[l]  << "  " << bitm.get(1, a[l]) << endl;
            sum += bitm.get(1, a[l]) + bitr.get(1, a[l]);
            sum += bitr.get(1, a[r + 1]);
        }
        ans %= mod;

    }

    cout << ans * qmi(n - k + 1, mod - 2)  % mod << endl;






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