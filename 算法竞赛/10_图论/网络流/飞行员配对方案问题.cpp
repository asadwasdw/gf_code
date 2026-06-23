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
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    memset(h,-1,sizeof h);
    while(cin>>a>>b)
    {
        if(a==b&&a==-1)break;
        add(a,b,1);
        add(b,a,0);
    }

    S = n+m+1;
    T = S+1;

    for(int i=1;i<=n;i++){
        add(S,i,1);
        add(i,S,0);
    } 

    for(int i=n+1;i<=n+m;i++){
        add(i,T,1);
        add(T,i,0);
    } 
    cout<<dinic()<<endl;

    for(int i=1;i<=n;i++){
        for(int j = h[i];~j;j=ne[j]){
            int v = e[j];
            if(f[j]==0&&v!=S){
                cout<<i<<" "<<v<<endl;
                break;
            }
        }
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