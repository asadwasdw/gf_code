#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int d[N];
int f[N];
int sz[N];
int ans = 0;
int n;

void dfs(int u,int fa)
{
   // cout<<u<<endl;
    sz[u]=1;
    for(auto t:edg[u])
    {
        if(t==fa)continue;
        dfs(t,u);
        sz[u]+=sz[t];
        d[u]+=d[t];
        //cout<<u<<" "<<d[u]<<endl;
    }
    d[u]+=sz[u]-1;

}

void dfs2(int u,int fa)
{

    for(auto t:edg[u])
    {
        if(t==fa)continue;
        f[t]=(f[u]-sz[t])+(n-sz[t]);
        dfs2(t,u);
    }

}

void solve()
{

    cin>>n;

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dfs(1,0);
    f[1]=d[1];
    dfs2(1,0);

   for(int i=1;i<=n;i++)cout<<f[i]<<endl;

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