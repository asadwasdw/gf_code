#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
map<int,int>mp;
vector<int> v;

void dfs(int x) {
    if(mp.count(x) == 0) return;
    if(mp[x] == 0) return;
    v.push_back(mp[x]);
    mp[x] = 0;
    dfs(2 * x); 
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        mp[x] ++;
    }

    int ans = 0;

    for(int i = 1; i <= 1e6; i ++) {
        if(mp.count(i) == 0) continue;
        if(mp[i] == 0) continue;
        v.clear();
        v.push_back(0);
        dfs(i);
        int a = 0,b = 0,c = 0;

        vector dp(v.size() + 1, vector (2, 0));
        int sum = 0;
        for(int i = 1; i < v.size(); i ++) {
            // cout << v[i] << " ";
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + v[i];
            sum += v[i];
        }
        // cout << dp[v.size() - 1][1] << " " << dp[v.size() - 1][0] << endl;
        ans += sum - max(dp[v.size() - 1][1], dp[v.size() - 1][0]);

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
        solve();
    }
}