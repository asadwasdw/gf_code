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

struct icecream {
    int t, w, v; // 所需时间， 美味度， 融化度
}ice[N];

int dp[N];

void solve()
{
    int n, m = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> ice[i].t >> ice[i].w >> ice[i].v;
        m += ice[i].t;
    }

    sort(ice + 1, ice + n + 1, [&](icecream a, icecream b) {
        return a.v * b.t > a.t * b.v;
    });

    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= ice[i].t; j --) {
            dp[j] = max(dp[j], dp[j - ice[i].t] + max(0, ice[i].w - (j - ice[i].t) * ice[i].v ));
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i ++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

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