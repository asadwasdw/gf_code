#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);

bool cmp(PII a,PII b)
{
    return a.second<b.second;
}
vector<int>ans;
bool vis[N];

void dfs(int u)
{
    for(auto t:edg[u])
    {
        int v= t.first;
        int y = t.second;
        if(!vis[y]){
            vis[y]=true;
            dfs(v);
            ans.push_back(y);
        }
    }
}
int n = 0;
int sx = 0;
void solve()
{
    int a,b;
    n=0;
    while(cin>>a>>b)
    {
        if(a==b&&a==0)break;
        int c;
        cin>>c;
      
        edg[a].push_back({b,c});
        edg[b].push_back({a,c});
        vis[c]=false;
        n=max({n,a,b});
    }
    //memset(vis,0,sizeof vis);

    bool ky = true;
    for(int i=1;i<=n;i++){
       // cout<<edg[i].size()<<endl;
        if(edg[i].size()%2)ky=false;
        else sort(edg[i].begin(),edg[i].end(),cmp);
    }
    if(ky){
        //cout<<sx<<endl;
        dfs(sx);
        reverse(ans.begin(),ans.end());
        for(auto t:ans)cout<<t<<" ";cout<<"\n";
    }
    else {
        cout<<"Round trip does not exist.\n";
    }

    for(int i=1;i<=n;i++)
    {
        edg[i].clear();
    }
    ans.clear();
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    int a,b,c;
    while(cin>>a>>b)
    {
        if(a==b&&a==0)break;
        //cout<<a<<" "<<b<<endl;
        cin>>c;
        edg[a].push_back({b,c});
        edg[b].push_back({a,c});
        n=sx=0;
        sx=min(a,b);
        n=max({n,a,b});
        vis[c]=false;
        solve();
    }
}