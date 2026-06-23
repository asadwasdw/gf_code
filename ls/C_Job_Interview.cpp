#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int a[N];
int b[N];
int ans[N];

PII st[N];

map<PII,int> dp[N];
int n, m;


int dfs(int i, int x, int y, bool tg) {
    if(i == n + m + 2) return 0;
    if(x + y == n + m) return 0;
    if(dp[i][{x, y}]) return dp[i][{x, y}];

    // cout << i << " " << x << " " << y << endl;
    int res = 0;
    if(a[i] > b[i]) {
        if(x < n) res = dfs(i + 1, x + 1, y, tg) + a[i];
        else res = dfs(i + 1, x, y + 1, tg) + b[i];
    }

    if(a[i] < b[i]) {
        if(y >= m) res = dfs(i + 1, x + 1, y, tg) + a[i];
        else res = dfs(i + 1, x, y + 1, tg) + b[i];
    }

    if(!tg) {
        res = max(res, dfs(i + 1, x, y, true));
    }
    // cout << i << " " << x << " " << y  << " " << res << endl;
    return  dp[i][{x, y}] =  res;
}



void solve()
{

    cin >> n >> m;
    for(int i = 1; i <= n + m + 1; i ++) cin >> a[i];
    for(int i = 1; i <= n + m + 1; i ++) cin >> b[i];
    int nn = 0, nm = 0;
    for(int i = 1; i <= n + m; i ++) {
        ans[i] = ans[n + m + 1];
        st[i] = {nn, nm};
        if(a[i] > b[i]) {
            if(nn < n) ans[n + m + 1] += a[i], nn ++;
            else ans[n + m + 1] += b[i], nm ++;
        }
        else {
            if(nm < m) ans[n + m + 1] += b[i], nm++;
            else ans[n + m + 1] += a[i], nn++;
        }
    }
  
    dp[n + m + 1][{n - 1,m}] = a[n + m + 1];
    dp[n + m + 1][{n,m - 1}] = b[n + m + 1];

    int sum = 0;
    // cout << dp[3][{0, 1}] << endl;
    for(int i = 1; i <= n + m; i ++) {
        ans[i] += dfs(i + 1, st[i].first, st[i].second, true);
    }

    for(int i = 1; i <= n + m; i ++)cout << ans[i] << " ";
    cout << ans[n + m + 1] << endl;


    for(int i = 1; i <= n + m + 1; i ++) {
        st[i] = {0,0};
        ans[i] = 0;
        dp[i].clear();
    }
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