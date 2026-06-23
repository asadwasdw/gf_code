#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<vector<int>>edg(N);
int c[N];

int ans=0;
int st[N];

void dfs(int u,int fa,int p)
{
    st[u]=p;

    for(auto t:edg[u]){
        if(t==fa)continue;
        
        if(c[t]==c[u]&&p==st[t]){
            ans=1;
            return ;
        }
        if(c[t]==c[u])continue;
        if(st[t])continue;
        dfs(t,u,p);
    }
}





void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    for(int i=1;i<=n;i++)cin>>c[i];

    for(int i=1;i<=n;i++)
    {
        if(!st[i])dfs(i,0,i);
    }
    if(ans)cout<<"Yes";
    else cout<<"No";

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