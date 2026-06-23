#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e6 + 10;
typedef pair<int, int> PII;


void dfs(vector<ll> a, ll sum) {
    // for(auto t : a) cout << t << " "; cout << endl;
    // cout << sum << endl;

    if(a.size() == 1) {
        cout << sum << endl;
        return;
    }
    int n = a.size();
    for(int i = 0; i < n; i ++) {
        vector<ll> b;
        int i2 = n - 1 - i ;
        if(i2 == i) continue;
        for(int j = 0; j < n; j ++) {
            if(j == i2) continue;
            int x = a[j];
            if(j == i) x += a[i2];
            b.push_back(x);
        }
        dfs(b, sum + a[i] * a[i2] % mod * ((a[i] + a[i2])%mod) % mod);
    }
}

void solve(){
    vector<ll> a;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        ll x; cin >> x; a.push_back(x); 
    }

    // dfs(a, 0);
    ll ans = 0, sum = a[0];
    for(int i = n - 1; i ; i --) {
        ans += (a[0] * a[i]) % mod * ((a[0] + a[i]) % mod) % mod;
        a[0] += a[i];
        a[0] %= mod;
        ans %= mod;
    }
    cout << ans % mod<< endl;
    
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}