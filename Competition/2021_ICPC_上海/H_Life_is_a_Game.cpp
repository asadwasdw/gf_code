#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edge(N);
int n,m,q;
int f[N],w[N];
int ans[N];
 struct edg{
    int u,v,w;
};
vector<edg>e;
bool cmp(edg a,edg b){
    return a.w<b.w;
}

int find(int x)
{
    if(x != f[x])f[x] = find(f[x]);
    return f[x];
}
void add(int a,int b)
{
    edge[a].push_back(b);
}
int tot;

void  KruskalTree(){
    sort(e.begin(),e.end(),cmp);
    tot = n;
    for(auto tt : e){
        int fa = find(tt.v);
        int fb = find(tt.u);

        if(fa == fb)continue;
      
        tot++;
      
        f[tot] = f[fa] = f[fb] = tot;
        w[tot] = tt.w;
        add(tot,fa);add(tot,fb);
    }
}

int sum[N];
int v[N][20];
int fa[N][20];

void dfs1(int u)
{
    if(u<=n){
        sum[u] = w[u];
        return ; 
    }
    for(auto v:edge[u]){

        dfs1(v);
        fa[v][0] = u;
        sum[u]+=sum[v];
    }
}

void dfs2(int u)
{
    v[u][0] = max(0ll,w[fa[u][0]] - sum[u]);

    for(int i = 1;i<20;i++){
        fa[u][i] = fa[fa[u][i-1]][i-1];
        v[u][i] = max(v[u][i-1],v[fa[u][i-1]][i-1]);
    }

    for(auto v:edge[u]){
        dfs2(v);
    }
}

int query(int x,int y)
{
    for(int i = 19;i>=0;i--){
        if( fa[x][i] &&y  >= v[x][i]){
            x = fa[x][i];
        }
    }
    return sum[x];
}



void solve()
{
    
    cin>>n>>m>>q;
    for(int i=0;i<N;i++)f[i] = i,w[i] = 0;
    for(int i =1;i<=n;i++)cin>>w[i],ans[i] = w[i];

    for(int i= 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }

    KruskalTree();

    dfs1(tot);
  
    dfs2(tot);
  //  cout<<w[fa[8][0]] - sum[8]<<endl;
  //  for(int i = 1;i<=tot;i++)cout<<v[i][0]<<" "<<sum[i]<<" "<<i<<endl;

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<y+query(x,y)<<endl;
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