#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
vector<vector<int>>E(N);


int dfn[N],low[N],tim;
stack<int>stk;
int dcc_cnt,id[N];

void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tim;
    stk.push(u);

    for(auto v:E[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=fa)
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        dcc_cnt++;
        while(1)
        {
            int v = stk.top();stk.pop();
            id[v] = dcc_cnt;
            if(u==v)break;
        }
    }

}
int fa[N][20],deep[N];

void dfs2(int x,int father)
{
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;(1<<i)<=deep[x];i++){
        fa[x][i]=fa[ fa[x][i-1] ][i-1];
    }

    for(auto v:edg[x])
    {
        if(v!=father)dfs2(v,x);
    }
}

int lca(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    for(int i=19;i>=0;i--)
        if((deep[x]-(1<<i))>=deep[y]){
            x=fa[x][i];
        }
            
    if(x==y)return x;

    for(int i=19;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }

    return fa[x][0];
}

int len(int x,int y)
{
    return deep[x]+deep[y]-2*deep[lca(x,y)];
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
        // add(a,b);
        // add(b,a);
    }

    tarjan(1,-1);

    for(int i=1;i<=n;i++)
    {
        for(auto v:E[i])
        {
            if(id[v]!=id[i])edg[id[v]].push_back(id[i]);
        }
    }

    dfs2(1,-1);
    int q;cin>>q;
    while(q--)
    {
        int a,b;cin>>a>>b;
       cout<<len(id[a],id[b])<<endl;
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