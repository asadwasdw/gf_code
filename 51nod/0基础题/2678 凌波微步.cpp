#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define int long long
const int N=10010;

typedef pair<int,int>PII;

struct Node
{
   int x,y;
}node[N];


double jl(Node a,Node b)
{
    int x=a.x-b.x;
    int y=a.y-b.y;
   // cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<endl;
    return abs(x)+abs(y);
}

int h[N],ne[N],e[N],idx,w[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int cnt=0;

int dis[N];
bool vis[N];


void dj(int x)
{
    memset(dis,0x3f,sizeof dis);
    dis[x]=0;

    priority_queue<PII,vector<PII>,greater<PII>>q;

    q.push({0,x});
    while(q.size())
    {
        auto t=q.top();q.pop();

        if(vis[t.second])continue;
        vis[t.second]=true;

        for(int i=h[t.second];~i;i=ne[i])
        {
            int j=e[i];
            if(vis[j])continue;

            if(dis[j]>dis[t.second]+w[i])
            {
                dis[j]=dis[t.second]+w[i];
                q.push({dis[j],j});
            }

        }
    }

}

signed main()
{
    int xM,yM,xH,yH;
    cin>>xM>>yM>>xH>>yH;

    node[++cnt]={xM,yM};
    node[++cnt]={xH,yH};

    memset(h,-1,sizeof h);

    for(int i=1;i<=3;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        node[++cnt]={a,b};
        node[++cnt]={c,d};

        add(cnt,cnt-1,10);
        add(cnt-1,cnt,10);

    }

    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            add(i,j,jl(node[i],node[j]));
        //  cout<<i<<" "<<j<<" "<<jl(node[i],node[j])<<endl;
        }
    }

 //  cout<<jl(node[1],node[3])<<endl;

  dj(1);

  cout<<dis[2]<<endl;

 // for(int i=1;i<=cnt;i++)cout<<dis[i]<<endl;






}