#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=5e4+10;
const int INF=0x3f3f3f3f;
int n,m;
struct node
{
    int a,b,w;
}E[N];

int f[N];


int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}

bool cmp(node a,node b)
{
    return a.w>b.w;
}


int h[N],e[N],ne[N],w[N],idx;

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}


int fa[N][25];
int deep[N];
int W[N][25];
bool st[N];
void dfs(int u)
{
    st[u]=true;
    for(int i=1;(1<<i)<=deep[u];i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
        W[u][i]=min(W[fa[u][i-1]][i-1],W[u][i-1]);
    }


    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(st[j])continue;
        deep[j]=deep[u]+1;
        fa[j][0]=u;
        W[j][0]=w[i];
        dfs(j);
    }
}

int lca(int x,int y)
{
    if(find(x)!=find(y))return -1;
    if(deep[x]<deep[y])swap(x,y);
    int ans=INF;
    for(int i=20;i>=0;i--)
    {
        if(deep[x]-(1<<i)>=deep[y]){
            ans=min(ans,W[x][i]);
            x=fa[x][i];
        }
    }
    if(x==y) return ans;

    for(int i=20;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i]){
            ans=min(ans,min(W[x][i],W[y][i]));
            x=fa[x][i],y=fa[y][i];
        }
    }

    return ans = min(ans,min(W[x][0],W[y][0]));

}


int main()
{
    cin>>n>>m;
    memset(W,0x3f,sizeof W);

    for(int i=1;i<=n;i++)f[i]=i;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        E[i]={a,b,c};
    }

    sort(E+1,E+1+m,cmp);

    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int pl=find(E[i].a);
        int pr=find(E[i].b);


        if(pl==pr)continue;

        f[pl]=pr;

        add(E[i].a,E[i].b,E[i].w);
        add(E[i].b,E[i].a,E[i].w);
    }

    for(int i=1;i<=n;i++)
    {
        if(!st[i]){
            deep[i]=1;
            dfs(i);
            fa[i][0]=i;
            W[i][0]=INF;
        }
    }
    
    int q;cin>>q;

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}