#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int dp[N];
struct S{
    int a,b;
}s[N];

void solve()
{
    int n, p;
    cin >> n >> p;
    for(int i=1;i<=n;i++) {
        cin >> s[i].a >> s[i].b;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1] = p;
    for(int i=1;i<=n;i++) {
        dp[i] = min(dp[i],dp[i-1] + p);
        for(int j = 1;j <= n; j++) {
            dp[min(n,i + s[j].b)] = min(dp[min(n,i + s[j].b)], dp[i] + s[j].a);
        }

    }
    cout << dp[n] <<endl;









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