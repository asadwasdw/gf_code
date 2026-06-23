#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n,m,a[N];

struct BT
{
    vector<ll> tr, cnt;
    int _n;
    BT(int n){
        _n = n;
        tr.resize(n+10);
        cnt.resize(n+10);
    }
    void add(int x, int d, int d2){
        while(x <= _n){
            tr[x] += d;
            cnt[x] += d2;
            x += (x & -x);
        };
    }
    pair<ll, ll> query(int x){
        ll res = 0, c = 0;
        while(x > 0){
            res += tr[x];
            c += cnt[x];
            x -= (x & -x);
        }
        return make_pair(res, c);
    }
};


void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> a[i];
    vector<array<int, 3>> q(m);
    for(int i=0; i<m; ++i){
        int l,r;
        cin >> l >> r;
        q[i] = {l, r, i};
    }
    const int B = sqrt(n * log2(n));
    sort(q.begin(), q.end(), [&](array<int, 3> a, array<int, 3> b){
        if(a[0] / B != b[0] / B)return a[0] < b[0];
        if((a[0] / B) & 1)return a[1] < b[1];
        return a[1] > b[1];
    });
    ll res = 0;
    BT bt(100000);
    auto add = [&](int x){
        auto [sum, cnt] = bt.query(x);
        auto [sum2, cnt2] = bt.query(bt._n);
        res += cnt * x - sum;
        res += (sum2 - sum) - (cnt2 - cnt) * x;
        bt.add(x, x, 1);
    };
    auto del = [&](int x){
        bt.add(x, -x, -1);
        auto [sum, cnt] = bt.query(x);
        auto [sum2, cnt2] = bt.query(bt._n);
        res -= cnt * x - sum;
        res -= (sum2 - sum) - (cnt2 - cnt) * x;
    };
    
    vector<ll> ans(m);
    for(int i=0,l=1,r=0; i<m; ++i){
        while(l > q[i][0])l--, add(a[l]);
        while(r < q[i][1])r++, add(a[r]);
        while(l < q[i][0])del(a[l]), ++l;
        while(r > q[i][1])del(a[r]), --r;
        ans[q[i][2]] = res;
    }
    for(int i=0; i<m; ++i)cout << ans[i] * 2 << endl;






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