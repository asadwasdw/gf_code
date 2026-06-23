#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int n, k, ans;
int f[N];


int qmi(int a, int b)
{
    int res = 1 % mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    cin >> n >> k;

    int p0 = ((qmi(n, 2) - (2 * n % mod - 2)) * qmi(qmi(n, 2), mod - 2)) % mod;
    int p1 = (2 * qmi(qmi(n, 2), mod - 2)) % mod;
    p0 = (p0 + mod) % mod;
    p1 = (p1 + mod) % mod;
	cout << p0 << " " << p1 << endl;
    //当只进行一次操作时，黑球位于第一个位置概率是p0
    f[1] = p0;
    //cout << (p0 + mod) % mod << " " << p1 << endl;
    //计算经过k次操作后黑球仍位于第一个位置的概率
    for (int i = 2; i <= k; i ++ )
    {
        f[i] = (f[i - 1] * p0 % mod + (((1 - f[i - 1] + mod) % mod) * p1) % mod) % mod;
    }

    //计算期望
    ans = f[k]; //位于第一个位置的期望
	cout << ans << endl;
    ans = (ans + ((((1 - f[k] + mod) % mod) * qmi(n - 1, mod - 2) % mod) * ((n + 2) * (n - 1) / 2 % mod))) % mod; //剩下n-1个位置的期望
    ans %= mod;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}
