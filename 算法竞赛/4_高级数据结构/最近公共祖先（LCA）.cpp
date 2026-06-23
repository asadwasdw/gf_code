//https://www.luogu.com.cn/problem/P3379

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n,m,s;

const int N=1e6+10;

int h[N],ne[N],e[N],idx;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


int fa[N][20],deep[N];

void dfs(int x,int father)
{
   //    cout<<x<<" "<<father<<endl;
    deep[x]=deep[father]+1;
    fa[x][0]=father;


    for(int i=1; (1<<i) <= deep[x]; i++)
    for(int i=1;(1<<i)  <= deep[x]; i++)
    
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }

    

    for(int i=h[x];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father)continue;;
        dfs(j,x);
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

    for(int i=19;i>=0;i--){
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i],y=fa[y][i];
        }
    }

    return fa[x][0];

}




int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs(s,0);

    while(m--)
    {
        int a,b;cin>>a>>b;
        //cout<<deep[a]<<" "<<deep[b]<<endl;

        cout<<LCA(a,b)<<endl;
    }


}