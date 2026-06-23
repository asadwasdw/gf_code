#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
const int N = 1e5+10;
vector<int>G[N];
vector<int>rG[N];
int cnt = 0;
vector<int>S;
int vis[N],sccno[N];

void dfs1(int u)
{
    if(vis[u])return;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        dfs1(G[u][i]);
    }
    S.push_back(u);
}

void dfs2(int u){
    if(sccno[u])return;
    sccno[u]=cnt;
    for(int i=0;i<rG[u].size();i++){
        dfs2(rG[u][i]);
    }
}

void Kosaraju(int n){
    cnt =0;
    S.clear();
    memset(vis,0,sizeof vis);
    memset(sccno,0,sizeof sccno);
    for(int i=1;i<=n;i++)dfs1(i);
     for(auto t:S)cout<<t<<" ";cout<<endl;
    for(int i=n-1;i>=0;i--){
        if(!sccno[S[i]]){
            ++cnt;
            dfs2(S[i]);
        }
    }
}

int main()
{
    int n,m,u,v;
    while(cin>>n>>m,n!=0||m!=0){
        for(int i=1;i<=n;i++){
            G[i].clear();
            rG[i].clear();
        }

        for(int i=1;i<=m;i++){
            cin>>u>>v;
            G[u].push_back(v);
            rG[v].push_back(u);
        }
        Kosaraju(n);
        if(cnt==1)cout<<"Yes\n";
        else cout<<"No\n";
    }
}


