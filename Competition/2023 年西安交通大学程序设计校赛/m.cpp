#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int t1[N],t2[N];

vector<vector<int>>edg(N+10);

void dfs(int u,int fa)
{
    for(auto t:edg[u])
    {
        if(t==fa)continue;

        dfs(t,u);

        t1[u]=min(t1[t],t1[u]);
        t2[u]=max(t2[t],t2[u]);
    }

   // cout<<u<<" "<<t1[u]<<" "<<t2[u]<<endl;
}


int ans[N];

void solve()
{

    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int x;cin>>x;
        edg[x].push_back(i+1);
        edg[i+1].push_back(x);
      //  cout<<x<<" "<<i+1<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        t1[x]=t2[x]=i;
    }


    dfs(1,-1);

    for(int i=1;i<=n;i++)
    {
        ans[t1[i]]++;
        ans[t2[i]]--;
    }

    for(int i=1;i<=n;i++)
    {
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }








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