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


void solve1() {
    int n = 3, m = 3;
    vector<int> v = {0, 1, 1, 2};
    vector<int> w = {0, 3, 4, 6};

    for(int t = 0; t < (1 << n); t ++) {
        string s;
        int sum_v = 0, sum_w = 0;
        for(int i = 0; i < n; i ++) {
            if((t >> (n - 1 - i)) & 1) {
                s += '1';
                sum_v += v[i + 1];
                sum_w += w[i + 1];
            } else {
                s += '0';
            }
        }
        cout << s << " " << sum_v << " " << sum_w << " " << (sum_v <= m) << endl;
    }
}


void solve2()
{
    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1, 0), w(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -INF));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            if(j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i ++) ans = max(ans, dp[n][i]);
    cout << ans;
}

void solve3() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1, 0), w(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    // dp[0][0] = 0;

    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            if(j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }

    cout << dp[n][m];
}

void solve4() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1, 0), w(n + 1, 0);
    vector<int> f(m + 1, 0); // 所维护的最后一行的信息，在一开始时是第0行， dp[0][j] = f[j]

    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i ++) {
        vector<int> g(m + 1, 0); // 当前行的信息
        for(int j = 0; j <= m; j ++) {
            if(j < v[i]) g[j] = f[j];
            else g[j] = max(f[j], f[j - v[i]] + w[i]);
        }
        swap(g, f); // 交换两个数组是o1的，
    }
    cout << f[m];
}

void solve5() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1, 0), w(n + 1, 0);
    vector<int> dp(m + 1, 0);

    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= v[i]; j --) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m];
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
        solve4();
    }
    return 0;
}