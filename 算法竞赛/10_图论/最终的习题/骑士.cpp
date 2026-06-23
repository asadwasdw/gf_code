#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int val[N],vis[N];
int father[N],mark;


int check_c(ll u)
{
    vis[u]=true;
    int f = father[u];
    if(vis[f])return f;
    return check_c(f);
}
ll dp[N][2];
void dfs(int u)
{
    dp[u][0]=0;
    dp[u][1]=val[u];
    vis[u]=true;

    for(int v:edg[u]){
        if(v==mark)continue;
        dfs(v);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][1],dp[v][0]);
    }
}

ll solve(int u)
{
    ll res = 0;
    mark=check_c(u);
    dfs(mark);
    res = max(res,dp[mark][0]);
    mark = father[mark];
    dfs(mark);
    res= max(res,dp[mark][0]);
    return res;
}


signed main()
{
     ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int d;cin>>val[i]>>d;
        edg[d].push_back(i);
        father[i]=d;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])ans+=solve(i);
    }
    cout<<ans<<endl;
}
