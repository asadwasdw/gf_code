#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int a[N];
vector<PII>ans;

int vis[N];
int res[N];


int tot=0;

void dfs(int u,int fa){
    vis[u]=1;
    for(auto T:edg[u]) {
        int v = T.first, id = T.second;
        if(v==fa)continue;
        if(vis[v]==2)continue;
        if(vis[v]==1) {
            if(res[u]){
                ans.push_back({id,res[u]});
                res[u]=0;
            }
            else res[u]=id;
            continue;
        }
        dfs(v,u);
        if(res[v]) {
            ans.push_back({id,res[v]});
            res[v]=0;
        }
        else if(res[u]) {
            ans.push_back({res[u],id});
            res[u] = 0;
        }
        else res[u]=id;
    }
    vis[u]=2;
}


void solve()
{
    int n;cin>>n;
    map<int,int>mp1,mp2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!mp1[a[i]+i])mp1[a[i]+i]=++tot;
        if(!mp2[a[i]-i])mp2[a[i]-i]=++tot;
        int u=mp1[a[i]+i],v=mp2[a[i]-i];
        // cout<<u<<" "<<v<<"\n";
        edg[u].push_back({v,i});
        edg[v].push_back({u,i});
    }

    bool flag = true;
    for(int i=1;i<=tot;i++){
        if(vis[i])continue;
        dfs(i,-1);
        if(res[i])flag =false;
    }

    if(flag) {
        cout<<"Yes\n";
        for(auto t:ans){
            cout<<t.first<<' '<<t.second<<"\n";
        }
    }
    else cout<<"No\n";

    for(int i=1;i<=tot;i++){
        vis[i]=0;res[i]=0;
        edg[i].clear();
    }
    ans.clear();
    tot=0;
}


signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}