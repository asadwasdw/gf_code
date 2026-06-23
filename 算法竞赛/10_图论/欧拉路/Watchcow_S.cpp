#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e4+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

vector<int>ans;
int n,m;

void dfs(int u)
{

    for(auto &t:edg[u])
    {
        if(!t)continue;
        int x = t;
        t=0;
        dfs(x);
    }
    ans.push_back(u);
}


void solve()
{
    cin>>n>>m;


    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        //cout<<u<<" "<<v<<endl;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    dfs(1);

    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<endl;
   // for(int i=1;i<ans.size();i++)cout<<ans[i]<<"\n";




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