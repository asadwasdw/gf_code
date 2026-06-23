#include<iostream>
#include<algorithm>
#define int long long

using namespace std;

typedef long long ll;

const int N = 200010, mod = 1e9 + 7;

int fact[N], infact[N];
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

}

int C(int a,int b)
{
    return (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve() {
    int n, k; 
    cin >> n >> k;
    int a = 0, b = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        if(x) b ++;
        else a ++;
    }
    ll ans = 0;
    for(int i = 0; i <= n; i ++) {
        int j = k - i;
        if(i > a || j > b) continue;
        if(i > j) continue;
        ans += C(a, i) * C(b, j) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}


signed main()
{
    init();
    int n;
    cin>>n;
    while(n --) {
        solve();
    }
    return 0;
    
}


