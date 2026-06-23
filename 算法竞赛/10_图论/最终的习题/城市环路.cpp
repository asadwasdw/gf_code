#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int w[N];
bool isring[N];
int ring[N],ringc;
int dfn[N],tim,fa[N];

void dfs(int u)
{
    dfn[u]=++tim;
    for(auto v:edg[u])
    {
        if(v==fa[u])continue;
        if(!dfn[v]){
            fa[v]=u;
            dfs(v);
        }
        else if(dfn[v]>dfn[u]){
            while(v!=u){
                ++ringc;
                ring[ringc]=v;
                isring[v]=true;
                v=fa[v];
            }
            isring[v]=true;
            ++ringc;
            ring[ringc]=v;
        }
    }
}

int dp[N][2];


void dfs2(int u,int fa)
{
    dp[u][1]=w[u];
    for(auto v:edg[u])
    {
        if(isring[v])continue;
        if(v==fa)continue;

        dfs2(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
}

int dp2[N][2];


void solve()
{
    memset(fa,-1,sizeof fa);
    int ans = 0;
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u); 
    }
    double k;cin>>k;
    dfs(1);
    //cout<<ringc<<endl;
    //for(int i=1;i<=ringc;i++)cout<<ring[i]<<" ";cout<<endl;

    for(int i=1;i<=ringc;i++){
        dfs2(ring[i],-1);
    }
    
    memset(dp2,0x8f,sizeof dp2);

    dp2[1][0]=dp[ring[1]][0];

    for(int i=2;i<=ringc;i++)
    {
        dp2[i][0]=max(dp2[i-1][0],dp2[i-1][1])+dp[ring[i]][0];
        dp2[i][1]=max(dp2[i][1],dp2[i-1][0]+dp[ring[i]][1]);
    }

    ans = max(dp2[ringc][1],dp2[ringc][0]);
    memset(dp2,0x8f,sizeof dp2);

    dp2[1][1]=dp[ring[1]][1];
    for(int i=2;i<=ringc;i++)
    {
        dp2[i][0]=max(dp2[i-1][0],dp2[i-1][1])+dp[ring[i]][0];
        dp2[i][1]=max(dp2[i][1],dp2[i-1][0]+dp[ring[i]][1]);
    }

    ans = max(ans,dp2[ringc][0]);
    cout<<ans*k<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
     cout << setprecision(1) << fixed;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}