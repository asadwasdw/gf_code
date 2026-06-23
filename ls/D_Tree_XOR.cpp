#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n;
int a[N];
ll sz[N];
ll ans[N];

void dfs(int u,int fa){

    sz[u]=1;
    for(auto v:edg[u]){
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];
        ans[1]+=(a[u]^a[v])*sz[v];
        //cout<<ans[1]<<endl;
    }
}

void dfs2(int u,int fa){
    if(u!=1){
        ans[u] = ans[fa]- (a[fa]^a[u])*(sz[u])+(a[fa]^a[u])*(n-sz[u]);
    }



    for(auto v:edg[u]){
        if(v==fa)continue;
        dfs2(v,u);
    }
}



void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dfs(1,0);
    //cout<<ans[1]<<endl;
    dfs2(1,0);

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++){
        edg[i].clear();
        ans[i]=0;
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