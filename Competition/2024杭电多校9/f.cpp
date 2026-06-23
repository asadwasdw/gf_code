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
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    vector<int> t(10);
    for (int i = 0; i < 10; i++) cin >> t[i];
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<int> f(m + 1);
    for (int i = 0; i < n; i++)
    for (int j = a[i]; j <= m; j++) {
        f[j] = max(f[j], f[j - a[i]] + b[i]);
    }
    vector<int> dp(m + 1);
    for (int i = 1; i <= m; i++){
        if (!f[i]) continue;
        int val = t[((f[i] * 10 + i - 1) / i) - 1];
        for (int j = i; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - i] + val * i);
        }
    }
    cout << dp[m] << "\n";




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}