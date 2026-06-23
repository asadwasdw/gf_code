#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int a[N];

struct hx{
    int n;
    ll h[N],p[N],P,mod;
    void init(int _n,ll _p, ll _mod) {
        n = _n, P = _p, mod = _mod;
        p[0] = 1;
        for(int i = 1; i <= n; i ++) {
            (h[i] = h[i - 1] * P + a[i])%=mod;
            (p[i] = p[i - 1] * P)%=mod;
            h[i]%=mod;
            p[i]%=mod;
        }
    }

    ll get(int l, int r) {
        if(l > r) return 0; 
        return (h[r] - (h[l - 1] * p[r - l + 1] %mod) + mod)%mod;
    }
}hx1, hx2;

ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % c;
        b >>= 1; 
    }
    return res;
}



void solve()
{
    int n, m;
    while(cin >> n >> m) {

        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            adj[a[i]].push_back(i);
        }


        hx1.init(n,10000189,1000000021);
        hx2.init(n,10000253,1000000207);

        auto check = [&](int len, int c) -> bool{ // 是否有相同子串
            ll HX1 = (hx1.get(n - len + 1, n) * hx1.P + c) % hx1.mod;
            ll HX2 = (hx2.get(n - len + 1, n) * hx2.P + c)  % hx2.mod;
            for(int i = adj[c].size() - 1; i >= 0; i --) {
                int j = adj[c][i];
                if(j < len) break;
                ll t1 = (hx1.get(j - len + 1, j));
                ll t2 = (hx2.get(j - len + 1, j));

                if(HX1 == t1 && t2 == HX2) {
                    return true;
                }
            }
            return false;
        };


        ll ans = 0;
        for(int i = 1; i <= m; i ++) {
            int l = 0, r = n;
            while(l < r) {
                int mid = (l + r + 1)>> 1;
                if(check(mid, i)) l = mid;
                else r = mid - 1;
            }
            int t = n - l + (adj[i].size() == 0);
            ans ^= (qmi(3, i, mod) * t) %mod;
            // cout << i << " "  << t <<endl;
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i ++) {
            adj[a[i]].clear();
        }
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