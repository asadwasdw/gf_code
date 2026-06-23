#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll dp[N][3];
vector<vector<int>>edg(N);

void dfs(int u,int fa){
    dp[u][0]=1;
    dp[u][1]=1;
    dp[u][2]=1;
    for(auto t : edg[u]){
        if(t==fa)continue;

        dfs(t,u);

        dp[u][0]*=(dp[t][0]+dp[t][1])%mod;
        dp[u][2]*=dp[t][0]%mod;

        dp[u][1]*=(dp[t][0]+dp[t][1]+dp[t][2])%mod;

        dp[u][1]=(dp[u][1]+mod)%mod;
        dp[u][2]=(dp[u][2]+mod)%mod;
        dp[u][0]=(dp[u][0]+mod)%mod;
    }

    dp[u][1]-=dp[u][2];
    dp[u][1]=(dp[u][1]+mod)%mod;
}

void solve()
{
    int n;cin>>n;

    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dfs(1,0);

    cout<<(dp[1][0]+dp[1][1])%mod<<endl;

    for(int i=1;i<=n;i++){
        if(edg[i].size())edg[i].clear();
    }

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}