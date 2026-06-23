#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 2e5+10;

struct e{
    int a,b,w;
}edg[N];

long long dis[N];

int main()
{
    memset(dis,0x3f,sizeof dis);

    int n,m,k;cin>>n>>m>>k;

    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edg[i]={a,b,w};
    }

    dis[1]=0;

    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        int a=edg[x].a;
        int b=edg[x].b;
        int w=edg[x].w;
        dis[b]=min(dis[b],dis[a]+w);
    }

    if(dis[n]==0x3f3f3f3f3f3f3f3f)dis[n]=-1;
    
    cout<<dis[n]<<endl;

}