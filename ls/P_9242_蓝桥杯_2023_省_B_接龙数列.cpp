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



void solve()
{
    int n;
    cin >> n;
    map<int,int> dp;
    map<int,int> cnt;
    int ans = n;
    for(int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        int l = s[0] - '0';
        int r = s[s.size() - 1] - '0';
        dp[r] = max(dp[r], dp[l] + 1);
    } 
    for(int i = 0; i <= 9; i ++) ans = min(ans, n - dp[i]);
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
    return 0;
}