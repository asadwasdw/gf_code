#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N =1e6+10;
int fa[N][25];
int l[N],r[N];
int tim;
int deep[N];
int rf[N];
int n;

struct g
{
    int to;
    int id;
    int w;
} e[N];

vector<vector<g>>edg(N);


void dfs(int u,int father)
{
    l[u]= ++tim;
    fa[u][0]=father;
    deep[u]=deep[father]+1;
    

    for(int i=1;(1<<i)<=deep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }

    for(auto t:edg[u])
    {
        if(t.to==father)continue;
        rf[t.id]=t.to;
        dfs(t.to,u);
    }

    r[u]=tim;
}

int lca(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);

    for(int i=24;i>=0;i--)
    {
        if(deep[x]-(1<<i)>=deep[y])x=fa[x][i];
    }

    if(x==y)return x;

    for(int i=24;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i],y=fa[y][i];
        }
    }

    return fa[x][0];
}



int tr[N];

void add(int u,int x)
{
    for(int i=u;i<N;i+= i&-i)tr[i]+=x;
}


int sum(int u)
{
    int res=0;
    for(int i=u;i;i-= i&-i)res+=tr[i];
    return res;
}

signed main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edg[x].push_back({y,i,w});
        edg[y].push_back({x,i,w});
        e[i]={0,i,w};
    }

    dfs(1,0);

    for(int i=1;i<n;i++)
    {
        int x=rf[e[i].id];
        add(l[x],e[i].w);
        add(r[x]+1,-e[i].w);
    }


    int q;
    cin>>q;
    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;

        if(op==2)
        {
            cout<<sum(l[x])+sum(l[y])-2*sum(l[lca(x,y)])<<endl;
        }
        else 
        {
            int t=rf[e[x].id];
            
            add(l[t],y-e[x].w);
            add(r[t]+1,e[x].w-y);
            e[x].w=y;
        }

    }


    
}
