#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-12;

struct e{
    int to,b,c;
};

vector<vector<e>> edg(N+10);

int n,m;


bool check(long double mid) {

    vector<long double>dp(n+10,-INF);
    dp[1] = 0;

    for(int u = 1; u <= n; u++) {
        for(auto j : edg[u]){
            long double w = j.b - j.c * mid;
            int v = j.to;

            dp[v] = max(dp[v], dp[u] + w);
        }
    }
    //cout<<mid<<" "<<dp[n]<<endl;
    return dp[n] > 0;
}




void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u,v,b,c;
        cin >> u >> v >> b >> c;
        edg[u].push_back({v, b, c});
    }


    long double l = 0,r = 1e6;

    while(r-l > eps){
        long double mid = (r + l)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.15Lf", l);

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}