#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int n, m;
string s;

int c[N];
void solve()
{
    cin >> n >> m;
    cin >> s;
    s = " " + s;

    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    vector<int> p(1, 0);
    for(int i = 1; i <= n; i ++) {
        p.push_back(i);
    }

    int ans = 0;

    do {
        int a = 0, b = 0;
        for(int i = 1; i <= n; i ++) {
            int j = p[i];
            if(b >= c[j]) {
                b ++;
            } else {
                if(s[i] == '1') a ++;
                else b ++;
            }
        }

        if(a >= m) ans = (ans + 1) % mod;

    }while(next_permutation(p.begin() + 1, p.end()));

    cout << ans << endl;
}

ll dp[1ll << 19][20];

void solve2() {
    cin >> n >> m;
    cin >> s;

    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }


    dp[0][0] = 1;

    for(int t = 0; t < (1 << n); t ++) {
        int x = __builtin_popcount(t);
        if(x == n) continue;

        for(int i = 0; i <= x; i ++) {
            if(!dp[t][i]) continue;
            for(int j = 0; j < n; j ++) {
                if((t >> j) & 1) continue;
                int nt = t | (1 << j);
                if(i >= c[j]) {
                    dp[nt][i + 1] = (dp[nt][i + 1] + dp[t][i]) % mod;
                } else {
                    if(s[x] == '1') {
                        dp[nt][i] = (dp[nt][i] + dp[t][i]) % mod;
                    } else {
                        dp[nt][i + 1] = (dp[nt][i + 1] + dp[t][i]) % mod;
                    }
                }
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i <= n - m; i ++) {
        ans = (ans + dp[(1 << n) - 1][i]) % mod;
    }

    cout << ans;
}



void solve3() {
    cin >> n >> m;
    cin >> s;
    
    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    sort(c + 1, c + n + 1);
    dp[0][0] = 1;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 0; j <= i; j ++) {
            ll num = min(i, ((i - 1) - j) + c[i] - 1 + 1);
            if(num > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j] * num) % mod;

            if(j > 0) {
                ll num = min(i, ((i - 1) - (j - 1)) + c[i] - 1 + 1); 
                ll num2 = i - num; // 总位置 i 减去录用位置，就是放弃位置
                
                if(num2 > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * num2) % mod;
            }
        } 
    }


    ll ans = 0;

    for(int i = 0; i <= n - m; i ++) {
        ans = (ans + dp[n][i]) % mod;
    }

    cout << ans;
}


void solve4() {
    cin >> n >> m;
    cin >> s;

    if(n <= 18) {
            for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }


    dp[0][0] = 1;

    for(int t = 0; t < (1 << n); t ++) {
        int x = __builtin_popcount(t);
        if(x == n) continue;

        for(int i = 0; i <= x; i ++) {
            if(!dp[t][i]) continue;
            for(int j = 0; j < n; j ++) {
                if((t >> j) & 1) continue;
                int nt = t | (1 << j);
                if(i >= c[j]) {
                    dp[nt][i + 1] = (dp[nt][i + 1] + dp[t][i]) % mod;
                } else {
                    if(s[x] == '1') {
                        dp[nt][i] = (dp[nt][i] + dp[t][i]) % mod;
                    } else {
                        dp[nt][i + 1] = (dp[nt][i + 1] + dp[t][i]) % mod;
                    }
                }
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i <= n - m; i ++) {
        ans = (ans + dp[(1 << n) - 1][i]) % mod;
    }

    cout << ans;
    } else {
         vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    sort(c + 1, c + n + 1);
    dp[0][0] = 1;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 0; j <= i; j ++) {
            ll num = min(i, ((i - 1) - j) + c[i] - 1 + 1);
            if(num > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j] * num) % mod;

            if(j > 0) {
                ll num = min(i, ((i - 1) - (j - 1)) + c[i] - 1 + 1); 
                ll num2 = i - num; // 总位置 i 减去录用位置，就是放弃位置
                
                if(num2 > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * num2) % mod;
            }
        } 
    }


    ll ans = 0;

    for(int i = 0; i <= n - m; i ++) {
        ans = (ans + dp[n][i]) % mod;
    }

    cout << ans;
    }
}

int a[N];
ll fact[N];
void solve5() {
    fact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = fact[i - 1] * i % mod;
    
    int n, m;
    cin >> n >> m;

    cin >> s;

    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    for(int j = 0; j <= n; j ++) {
        for(int i = 1; i <= n; i ++) {
            if(c[i] <= j) a[j] ++;
        }
    }

    vector<vector<ll>> g(n + 2, vector<ll>(n + 2, 0ll));
    g[0][0] = 1;

    for(int i = 0; i < n; i ++) {
        vector<vector<ll>> f(n + 2, vector<ll>(n + 2, 0ll));
        for(int j = 0; j <= i; j ++) {
            for(int k = 0; k <= i; k ++) {
                ll v = g[j][k];
                if(!v) continue;

                if(s[i] == '0') {
                    f[j + 1][k] = (f[j + 1][k] + v) % mod;
                } else {
                    f[j][k] = (f[j][k] + v) % mod;
                    ll x = a[j] - k;
                    if(x > 0) {
                        f[j][k + 1] = (f[j][k + 1] - x * v % mod + mod) % mod;
                        f[j + 1][k + 1] = (f[j + 1][k + 1] + x * v % mod) % mod;
                    }
                }


            }
        }

        swap(g, f);
    }

    ll ans = 0;
    for(int j = 0; j <= n - m; j ++) {
        for(int k = 0; k <= n; k ++) {
            ans = ans + g[j][k] * fact[n - k] % mod;
            ans %= mod;
        }
    }
    cout << ans;
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
        solve5();
    }
    return 0;
}