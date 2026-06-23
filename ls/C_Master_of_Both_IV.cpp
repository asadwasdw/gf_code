#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

const int B = 30;
struct basic{
    vector<ll> num;
    int cnt;
    basic(){num.resize(B + 1), cnt = 0;}
    bool insert(ll x) {
        for (int i = B - 1; i >= 0; i--) {
            if (x & (1ll << i)) {
                if (num[i] == 0) {num[i] = x, cnt++; return true;}
                x ^= num[i];
            }
        }
        return false;
    } 
};

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve()
{

    int n;cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    vector<vector<ll>> f(2 * n + 1);
    vector<ll> tot(2 * n + 1);
    for (int i = 0, cnt = 0; i < n; i++) {
        cnt++;
        if (i == n - 1 || a[i] != a[i + 1]) {
            for (int j = 0; j <= 2 * n; j += a[i]) {
                f[j].push_back(a[i]);
                tot[j] += cnt;
            }
            cnt = 0;
        }
    }

    ll ans = 0;
    
    for (int i = 0; i <= 2 * n; i++) {
        basic t;
        for (auto x : f[i]) {
            t.insert(x);
        }
        if (!t.insert(i)) {
            ans = (ans + qpow(2, tot[i] - t.cnt)) % mod;
        }
    }
    ans = (ans - 1 + mod) % mod;
    cout << ans << '\n';


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}