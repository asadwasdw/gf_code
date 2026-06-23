#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
vector<vector<int>>ring(N);

int f[N],tot;
int to[N],d[N],fto[N];
int n,q;
int root[N],step[N],l[N],len[N];
int fa[N][20];

void tppx()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)q.push(i);
    }

    while(q.size()){
        int u = q.front();q.pop();
        int v = to[u];
        d[v]--;
        if(d[v]==0)q.push(v);
    }
}


void dfs(int u,int fa,int rt,int dis)
{

    root[u]=rt;
    l[u]=dis;

    for(auto v:edg[u]){
        if(v==fa||d[v])continue;
        dfs(v,u,rt,dis+1);
    }
}

void dfs2(int u,int id,int az)
{
    if(step[u])return;
    int v =to[u];
    f[u]=id;
    len[id]++;
    step[u]=az;
    dfs2(v,id,az+1);
}


void pre()
{
    for(int i=1;i<=19;i++)
    {
        for(int u=1;u<=n;u++){
            fa[u][i]=fa[fa[u][i-1]][i-1];
        }
    }
}


int lca(int x,int y)
{
    if(l[x]<l[y])swap(x,y);
    for(int i=19;i>=0;i--)
    {
        if(l[x]-(1ll<<i)>=l[y]){
            x=fa[x][i];
        }
    }
    if(x==y)return x;

    for(int i=19;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];

}

bool check(int x1,int y1,int x2,int y2)
{
    if(max(x1,y1)!=max(x2,y2))return max(x1,y1)<max(x2,y2);
    if(min(x1,y1)!=min(x2,y2))return min(x1,y1)<min(x2,y2);
    return x1>=y1;
}


void solve()
{

    cin>>n>>q;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)cin>>to[i],d[to[i]]++,edg[to[i]].push_back(i),fa[i][0]=to[i];

    tppx();

    for(int i = 1;i<=n;i++){
        if(d[i]){
            dfs(i,0,i,0);
            if(!step[i])dfs2(i,++tot,1);
        }
    }
    pre();

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<root[i]<<" "<<l[i]<<endl;
    // }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(f[root[x]]!=f[root[y]]){
            cout<<"-1 -1\n";
        }
        else if(root[x]==root[y]){
            int LCA = lca(x,y);
            cout<<l[x]-l[LCA]<<" "<<l[y]-l[LCA]<<endl;
        }
        else {
            int t1 = root[x];
            int t2 = root[y];
            int ans1 = l[x]+(step[t2]-step[t1]+len[f[t1]])%len[f[t1]];
            int ans2 = l[y]+(step[t1]-step[t2]+len[f[t1]])%len[f[t1]];

            if(check(l[x],ans2,ans1,l[y]))cout<<l[x]<<" "<<ans2<<endl;
            else cout<<ans1<<" "<<l[y]<<endl;

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