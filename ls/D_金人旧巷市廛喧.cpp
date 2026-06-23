#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef pair<int,int> PII;
#define endl '\n'
const int N=10000,INF=0x3f3f3f3f;
const int mod= 998244353;
const double eps=1e-12;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node{
    int to,cost,cap,rev;
    node(int t,int cos,int ca,int re){to=t,cost=cos,cap=ca,rev=re;}
};
int pre[N],preve[N];
int dis[N];
vector<node>e[N];
void add(int from,int to,int cost,int cap){
    e[from].push_back(node(to,cost,cap,e[to].size()));
    e[to].push_back(node(from,-cost,0,e[from].size()-1));
}
bool spfa(int s,int t,int cnt){
    bool inq[N];
    memset(pre,-1,sizeof pre);
    for(int i=1;i<=cnt;i++){
        dis[i]=INF,inq[i]=false;
    }
    dis[s]=0;
    queue<int>q;
    q.push(s);
    inq[s]=true;
    while(q.size()){
        int u=q.front();q.pop();
        inq[u]=false;
        for(int i=0;i<e[u].size();i++){
            if(e[u][i].cap>0){
                int v=e[u][i].to,cost=e[u][i].cost;
                if(dis[u]+cost<dis[v]){
                    dis[v]=dis[u]+cost;
                    pre[v]=u;
                    preve[v]=i;
                    if(!inq[v]){
                        inq[v]=false;
                        q.push(v);
                    }
                }
            }
        }
    }
    if(dis[t])
    return dis[t]!=INF;
}
int mincost(int s,int t,int cnt){
    int cost=0;
    while(spfa(s,t,cnt)){
        int v=t,flow=INF;
        while(pre[v]!=-1){
            int u=pre[v],i=preve[v];
            flow=min(flow,e[u][i].cap);
            v=u;
        }
        v=t;
        while(pre[v]!=-1){
            int u=pre[v],i=preve[v];
            e[u][i].cap-=flow;
            e[v][e[u][i].rev].cap+=flow;
            v=u;
        }
        cost+=dis[t]*flow;
    }
    return cost;
}
int n,m,k;
int g[40][40],tot=3;
int id[40][40][2];
void slove(){
    cin>>n>>m>>k;
    int st=1,ed=2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            id[i][j][0]=tot++;
            id[i][j][1]=tot++;
            if(g[i][j]==1){
                add(id[i][j][0],id[i][j][1],0,1);
            }
            if(g[i][j]==0)add(id[i][j][0],id[i][j][1],1,1);
        }
    }
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        add(st,id[x][y][0],0,1);
    }
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        add(id[x][y][1],ed,-100,1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==-1)continue;
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=dy[k]+j;
                if(x<1||x>n||y<1||y>m)continue;
                if(g[x][y]==-1)continue;
                add(id[i][j][1],id[x][y][0],0,1);
            }
        }
    }
    //add(st,ed,0,1e9);
    cout<<-mincost(st,ed,tot+1)<<endl;
}
signed main()
{
    int T=1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin>>T;
    while(T--){
        slove();
    }
    return 0;
}