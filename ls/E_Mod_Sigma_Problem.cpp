#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];

struct gfBIT {
    int n;
    vector<int> tr;

    void clear() {
        tr.clear();
        tr.resize(n + 10, 0); 
    }

    void init(int _n) {
        n = _n;
        clear();
    }

    int lowbit(int x) {
        return (x) & (-x);
    }

    void update(int x, int d) {
        ++x;
        for(int i = x; i < n + 10; i += lowbit(i)) tr[i] += d;
    }

    ll sum(int x) {
        ++x;
        ll ans = 0;
        for(int i = x; i > 0; i -= lowbit(i)) ans += tr[i];
        return ans;
    }

    ll get(int l, int r) {
        return sum(r) - sum(max(0ll,l - 1));
    }

    void debug() {
        cout << n << endl;
        for(int i = 1; i <= n; i ++) {
            cout << get(i, i) << " \n"[i == n];
        }
    }
}tr1,tr2;


void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i]; 
        a[i] += a[i - 1];
        a[i] %= m;
        // cout << a[i] << " \n"[i == n];
    }

    tr1.init(m);
    tr2.init(m);
    tr1.update(0, 0);
    tr2.update(0, 1);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int sum = tr1.sum(a[i]);
        int cnt = tr2.sum(a[i]);

        ans += (cnt) * a[i] - sum;
        sum = tr1.sum(m) - sum;
        cnt = tr2.sum(m) - cnt;
    
        ans += cnt * m - (sum - cnt * a[i]);
        tr1.update(a[i],a[i]);
        tr2.update(a[i],1);
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
}