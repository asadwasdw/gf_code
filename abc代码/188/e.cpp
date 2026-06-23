#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

vector<vector<int>>edg(N);

int w[N];
int mn[N];

int ans = 0x8f8f8f8f;

int dfs(int u)
{
    if(mn[u])
    {
        return max(mn[u],w[u]);
    }

    for(auto t : edg[u])
    {
        mn[u]=max(mn[u],dfs(t));
    }

   // cout<<mn[u]<<" "<<w[u]<<endl;

    if(mn[u])ans=max(mn[u]-w[u],ans);

    return max(mn[u],w[u]);

}


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(mn[i]==0)dfs(i);
    }
    cout<<ans<<endl;



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