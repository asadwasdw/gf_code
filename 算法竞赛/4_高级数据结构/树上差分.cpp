//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P3128

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+10;

int h[N],e[N],ne[N],idx;
int fa[N][20],ans,cnt;
int D[N],deep[N];


void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dfs1(int x,int father)
{
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;(1<<i)<=deep[x];i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }

    for(int i=h[x];~i;i=ne[i])
    {
        int j=e[i];
        //cout<<j<<endl;
        if(j==father)continue;
        dfs1(j,x);
    }
}


int LCA(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);

    for(int i=19;i>=0;i--)
    {
        if(deep[x]-(1<<i)>=deep[y]){
            x=fa[x][i];
        }
    }
    if(x==y)return x;

    for(int i=19;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i],y=fa[y][i];
        }
    }

    return fa[x][0];
}



void dfs2(int u,int father)
{

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)continue;
        dfs2(j,u);
        D[u]+=D[j];
    }

    ans=max(D[u],ans);
}




int main()
{
    int n,m;
    cin>>n>>m;

    memset(h,-1,sizeof h);

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs1(1,-1);


    while(m--)
    {
        int a,b;
        cin>>a>>b;
        int lab=LCA(a,b);
        D[a]++,D[b]++,D[lab]--,D[fa[lab][0]]--;
    }

 

    dfs2(1,-1);
//for(int i=1;i<=n;i++)cout<<D[i]<<" ";cout<<endl;
    cout<<ans<<endl;
}
