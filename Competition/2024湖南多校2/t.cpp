#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
// #define int long long
constexpr int N = 2, LOGN = 30;
constexpr ll mod = 1e9 + 7, inf = 1e9;

struct Matrix {
	vector<vector<ll>> a;
	Matrix() {}
	Matrix(int n) {resize(n);}
	Matrix(const vector<vector<ll>> &a) : a(a) {}
	int size() const {
		return a.size();
	}
	void resize(int n) {
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i].assign(n, i);
			a[i][i] = 1;
		}
	}
	vector<ll> operator[](int idx) const {
        return a[idx];
    }
    vector<ll> &operator[](int idx) {
        return a[idx];
    }
    friend Matrix operator*(const Matrix &a, const Matrix &b) {
    	int n = a.size();
    	vector<vector<ll>> c(n, vector<ll> (n));
    	for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    	for (int k = 0; k < n; k++) {
    		c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    	}
    	return Matrix(c);
    }
};
Matrix matrix_pow(Matrix c, ll k) {
 	Matrix b(c.size());
	while (k) {
		if (k & 1) b = b * c;
		c = c * c;
		k >>= 1;
	}
	return b;
}

ll qpow(ll a, ll b) {
	a %= mod;
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
 
ll inv(ll x) {
	return qpow(x, mod - 2);
}
void solve(){
	ll a, b, n; cin >> a >> b >> n;
    ll k = a * inv(b) % mod;
    ll x0 = (-1 + k * k % mod + mod) % mod * inv(k * k + 1) % mod;
    ll y0 = 2 * k * inv(k * k + 1) % mod;
    cout << k << ' ' << y0 << ' ' << x0 << '\n';
 
    Matrix t({{x0, y0}, {-y0, x0}});
    Matrix ans({{1, 0}, {0, 0}});
    ans = ans * matrix_pow(t, n + 1);
    cout << (-ans[0][0] + mod) % mod << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
