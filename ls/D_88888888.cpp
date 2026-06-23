#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

typedef long long ll;

const int N = 1000010, mod = 998244353;



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

int A(int a,int b) {
    return (ll)fact[a] * infact[a - b] % mod;
}
int ans = 0;
int a[N];
int b[N];

int n,m = 0;


signed main()
{
    auto inv = [&](int x) -> int {
        return qmi(x, mod - 2, mod);
    };
    init();
    cin >> n;
    for(int i = 1; i <= 26; i ++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= 26; i ++) {
        vector<int>dp2(n + 1, 0);
        for(int j = 0; j <= n; j ++) {
            for(int k = 0; k <= a[i] && k + j <= n; k ++) {
                dp2[j + k] += dp[j] * C(n - j, k);
                dp2[j + k] %= mod;
            }
        }
        swap(dp,dp2);
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += dp[i] * inv(C(n, n - i)) % mod;
        ans %= mod;
    }
    cout << ans;
}


