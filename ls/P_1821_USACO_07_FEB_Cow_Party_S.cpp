#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<cstdlib>
using namespace std;
const int maxn=1005;
int e[maxn][maxn],e2[maxn][maxn];
int dis[maxn],dis2[maxn],vis[maxn],vis2[maxn];
void dij(int n,int s){
    for(int i=0;i<=n;i++)
        dis[i]=1e9;
    dis[s]=0;
    for(int i=1;i<=n;i++){
        int u=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis[j]<dis[u])u=j;
        vis[u]=1;
        for(int j=1;j<=n;j++){
            if(e[u][j]){
                int v=j;
                int w=e[u][j];
                if(dis[v]>dis[u]+w)
                    dis[v]=dis[u]+w;
            }
        }
    }
}
void dij2(int n,int s){
    for(int i=0;i<=n;i++)
        dis2[i]=1e9;
    dis2[s]=0;
    for(int i=1;i<=n;i++){
        int u=0;
        for(int j=1;j<=n;j++)
            if(!vis2[j]&&dis2[j]<dis2[u])u=j;
        vis2[u]=1;
        for(int j=1;j<=n;j++){
            if(e2[u][j]){
                int v=j;
                int w=e2[u][j];
                if(dis2[v]>dis2[u]+w)
                    dis2[v]=dis2[u]+w;
            }
        }
    }
}
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        int tmp=e[u][v]?e[u][v]:1e9;
        e[u][v]=e2[v][u]=min(tmp,w);
    }
    dij(n,s);
    dij2(n,s);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i == s) continue;
        // cout << dis[i] << ' ' << dis2[i] << endl;
        ans=max(ans,dis[i]+dis2[i]);
    }=
    cout<<ans;
    return 0;
}