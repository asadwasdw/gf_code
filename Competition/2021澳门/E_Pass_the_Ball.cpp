#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

using db = __float128;
const db PI = acos(-1);
int limit = 1; //补齐的2的整数幂N
int L;//二进制的位数
int R[N]; //二进制翻转
// using Complex = complex<db>;
struct Complex {
    db x, y;
    Complex (db x = 0, db y = 0) : x(x), y(y) {}
    //复数乘法： 模长相乘，幅角相加
    Complex operator * (Complex J) {
        return Complex(x * J.x - y * J.y, x * J.y + y * J.x);
    }
    Complex operator - (Complex J) {
        return Complex(x - J.x, y - J.y);
    }
    Complex operator + (Complex J) {
        return Complex(x + J.x, y + J.y);
    }
}a[N], b[N];
void FFT(Complex *A, int type) {
    for (int i = 0; i < limit; ++i) if (i < R[i]) swap(A[i], A[R[i]]);

    for (int mid = 1; mid < limit; mid <<= 1) {
        Complex wn(cosl(PI / mid), type * sinl(PI / mid));

        for (int len = mid << 1, pos = 0; pos < limit; pos += len) {
            Complex w(1, 0);

            for (int k = 0; k < mid; k++, w = w * wn) {
                Complex x = A[pos + k];
                Complex y = w * A[pos + mid + k];
                A[pos + k] = x + y;
                A[pos + mid + k] = x - y;
            }
        }
    }
    if(type == 1) return;
    for (int i = 0; i <= limit; i++) 
        A[i].x /= limit, A[i].y /= limit;
}

void solve(){
    int n, q;cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> vis(n + 1);
    vector<vector<vector<int>>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        int len = 1;
        vector<int> tmp{i};
        int u = p[i];
        while (u != i) {
            tmp.push_back(u);
            len++;
            vis[u] = true;
            u = p[u];
        }
        g[len].push_back(tmp);
    }
    vector<vector<int>> f(n + 1);
    vector<int> idx;
    for (int j = 1; j <= n; j++) {
        if (g[j].size()) {
            idx.push_back(j);
            f[j].resize(j);
            for (auto t : g[j]) {
                int m = t.size();
                for (int i = 0; i < 2 * m; i++) {
                    a[i].x = t[i % m];
                }
                for (int i = 0; i < m; i++) {
                    b[m - i - 1].x = t[i];
                }
                limit = 1, L = 0;
                while(limit <= 3 * m)
                    limit <<= 1, L++;
                for (int i = 0; i < limit; i++)
                    R[i] = (R[i >> 1] >> 1 | ((i & 1) << (L - 1)));
                FFT(a, 1);
                FFT(b, 1);
                for (int i = 0; i <= limit; i++)
                    a[i] = a[i] * b[i];
                FFT(a, -1);
                for (int i = 0; i < m; i++) {
                    f[j][i] += ll(a[i + m - 1].x + 0.5);
                }
            }
        }
    }
    while (q--) {
        int k; cin >> k;
        ll ans = 0;
        for (auto len : idx) {
            ans += f[len][k % len];
        }
        cout << ans << '\n';
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