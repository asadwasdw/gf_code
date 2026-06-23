#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int n,m;
int st[16];
int ans = 0;


void dfs(int u,int cnt,int dis)
{
    //cout<<u<<endl;
    if(cnt>n)
    {
        return;
    }
    ans=max(dis,ans);

    for(auto t:edg[u])
    {
        int v= t.first;
        int w=t.second;
        if(st[v])continue;
        st[v]=true;
        dfs(v,cnt+1,w+dis);
        st[v]=false;
    }
}


void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edg[a].push_back({b,w});
        edg[b].push_back({a,w});
    }
    for(int i=1;i<=n;i++)edg[0].push_back({i,0});

    dfs(0,0,0);
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