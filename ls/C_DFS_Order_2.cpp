#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=510+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

template<class T>
constexpr T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr ll mul(ll a, ll b, ll p) {
    ll res = a * b - ll(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<ll P>
struct MLong {
    ll x;
    constexpr MLong() : x{} {}
    constexpr MLong(ll x) : x{norm(x % getMod())} {}
    
    static ll Mod;
    constexpr static ll getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(ll Mod_) {
        Mod = Mod_;
    }
    constexpr ll norm(ll x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr ll val() const {
        return x;
    }
    explicit constexpr operator ll() const {
        return x;
    }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong &operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MLong &a) {
        ll v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MLong &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(ll x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        ll v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};


const int P = 998244353;//模数
using mint = MInt<P>;
vector<vector<int>>edg(N);
int n;
mint dp[N][N],fac[N],inv[N];
int tot[N],num[N];

void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = inv[i - 1] / i;
    }
}

mint dfs1(int u, int fa) {

    mint res = 1;
    num[u] = 1;
    for(auto v:edg[u]) {
        if(v == fa) continue;
        res *= dfs1(v,u);
        tot[u] += 1;
        num[u] += num[v];
    }
    res *= fac[tot[u]];
     //cout<<u<<' '<<tot[u]<<' '<<num[u]<<endl;
    return res;
}

void dfs2(int u,int fa) {
    //cout<<u<<' '<<tot[u]<<' '<<num[u]<<endl;
    vector<vector<mint>>f(n + 10, vector<mint>(n + 10, 0));
    f[0][0] = 1;

    for(auto v:edg[u]) {
        if(v == fa) continue;
        for(int i = tot[u]; i >=1; i--) {
            for(int sz = num[u]; sz >= num[v]; sz--) {
                f[i][sz] += f[i-1][sz - num[v]];
            }
        }
    }

    for(auto v:edg[u]) {
        if(v == fa) continue;
        for(int i = 1; i<= tot[u]; i++) {
            for(int sz = num[v]; sz <= num[u]; sz++) {
                f[i][sz] -= f[i-1][sz - num[v]]; 
            }
        }

        vector<mint>g(n+10);

        for(int i = 0; i < tot[u];i++) {
            for(int k = 0;k <= num[u]; k++) {
                g[k+1] += fac[i] * fac[tot[u] - 1 - i] * f[i][k];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int k = 1; k <= n; k++) {
                if(i + k <= n) {
                    dp[v][i + k] += g[k]*dp[u][i];
                }
            }
        }


        for(int i = tot[u]; i >=1; i--) {
            for(int sz = num[u]; sz >= num[v]; sz--) {
                f[i][sz] += f[i-1][sz - num[v]];
            }
        }


    }



    for(auto v:edg[u]) {
        if(v == fa) continue;
        dfs2(v, u);
    }
}





void solve()
{
    init();
     cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dp[1][1] = dfs1(1, 0);
    dfs2(1,0);
   // cout << dp[1][1] <<endl;

    for(int i = 1; i <= n; i++) {

        mint sum = 0;
        for(int j = 1; j <= n; j++) sum += dp[i][j];

        for(int j = 1; j <= n; j++) {
            cout<<dp[i][j] * dp[1][1] / sum <<" \n"[j == n];
        }
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}