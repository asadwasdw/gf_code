#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dp[N][2];

void dfs(int u,int fa) {
    dp[u][1]=1;
    dp[u][0]=1;

    for(auto v:edg[u]) {
        if(v == fa) continue;
        dfs(v,u);
        dp[u][1] *= dp[v][0];
        dp[u][0] *= dp[v][0]+dp[v][1];
        dp[u][0] %=mod; 
        dp[u][1] %=mod; 
    }
    // cout<<u<<" "<<dp[u][1]<<" "<<dp[1][0]<<endl;
}

void solve()
{

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dfs(1,-1);
    cout<<(dp[1][0]+dp[1][1])%mod<<endl;







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