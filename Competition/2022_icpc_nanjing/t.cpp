#include<bits/stdc++.h>
using namespace std;
const int N=4e5+7;
int T,n,tot,flag;
int a[N],vis[N],res[N];
vector<pair<int,int>>G[N];
vector<pair<int,int>>ans;
void dfs(int u,int fa){
    vis[u]=1;
    for(auto e:G[u]){
        int v=e.first,id=e.second;
        if(v==fa)continue;
        if(vis[v]==2)continue;
        if(vis[v]==1){
            if(res[u]){
                ans.push_back({res[u],id});
                res[u]=0;
            }
            else res[u]=id;
            continue;
        }
        dfs(v,u);
        if(res[v]){
            ans.push_back({id,res[v]});
            res[v]=0;
        }
        else if(res[u]){
            ans.push_back({id,res[u]});
            res[u]=0;
        }
        else res[u]=id;
    }
    vis[u]=2;
    // cout<<u<<" "<<res[u]<<"\n";
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    map<int,int>mp1,mp2;
    for(int i=1;i<=n;i++){
        if(!mp1[a[i]+i])mp1[a[i]+i]=++tot;
        if(!mp2[a[i]-i])mp2[a[i]-i]=++tot;
        int u=mp1[a[i]+i],v=mp2[a[i]-i];
        // cout<<u<<" "<<v<<"\n";
        G[u].push_back({v,i});
        G[v].push_back({u,i});
    }
    flag=1;
    for(int i=1;i<=tot;i++){
        if(vis[i])continue;
        dfs(i,-1);
        if(res[i]){
            flag=0;break;
        }
    }
    if(!flag)cout<<"No\n";
    else{
        cout<<"Yes\n";
        for(auto v:ans)cout<<v.first<<" "<<v.second<<"\n";
    }
    for(int i=1;i<=tot;i++){
        vis[i]=0;res[i]=0;
        G[i].clear();
    }
    ans.clear();
    tot=0;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
    return 0;
}