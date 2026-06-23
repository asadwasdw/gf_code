#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m,S,T;
int h[N],ne[N],e[N],idx,f[N];
int d[N],cur[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    f[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;

    e[idx]=a;
    f[idx]=0;
    ne[idx]=h[b];
    h[b]=idx++;
}

bool bfs(){
    memset(d,-1,sizeof d);
    queue<int>q;
    q.push(S);
    d[S]=0;
    cur[S]=h[S];
    while(q.size()){

        int u = q.front();q.pop();
        for(int i=h[u];~i;i=ne[i]){
            int v = e[i];

            if(f[i]&&d[v]==-1){
                d[v]=d[u]+1;
                cur[v]=h[v];
                q.push(v);
                if(v==T)return true;
            }
        }
    }

    return false;
}

int find(int u,int limit)
{
    if(u==T)return limit;
   // cout<<u<<" "<<limit<<endl;
    int flow = 0;

    for(int i = cur[u];~i&&flow<limit;i=ne[i]){//flow<limit 优化1
        int v = e[i];                           // i = cur[u] 优化2 不跑已经满的边
        cur[u] = i;

        if(f[i] && d[v]==d[u]+1){//有容量且在下一层
            int t = find(v,min(f[i],limit- flow));
            if(!t)d[v]=-1;// 优化3 不行的点不跑了

            f[i]-=t;
            f[i^1]+=t;
            flow+=t;
        } 
    }

    return flow;
}


int dinic(){
    int ans = 0;
    int flow;
    while(bfs())//找一下能不能有新的流，同时建立分层的，防止环，让dfs跑最短路
    {
        while(flow = find(S,INF))//找
            ans+=flow;
    }
    return ans;
}




void solve()
{
    int x,y;
    cin>>n>>m>>x>>y;
    S = 0 ,T = n+1;
    while(x--){
        int t ;cin>>t;
        add(S,t,INF);
    }
    while(y--){
        int t;cin>>t;
        add(t,T,INF);
    }
    
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    cout<<dinic()<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}