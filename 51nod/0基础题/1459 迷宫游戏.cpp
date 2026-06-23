#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N=1e6+10;

int h[N],ne[N],e[N],idx,w[N];

typedef pair<int,int>PII;

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dis[N];
int vis[N];
int fj[N];
int fs[N];

void dj(int x)
{
    memset(dis,0x3f,sizeof dis);
    dis[x]=0;
    fs[x]=fj[x];

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,x});

    while(q.size())
    {
        auto t=q.top();q.pop();

       //cout<<t.second<<endl;

        if(vis[t.second])continue;
        vis[t.second]=true;

        for(int i=h[t.second];~i;i=ne[i])
        {
            int j=e[i];
            if(vis[j])continue;
          //  cout<<j<<endl;

            if(dis[j]>dis[t.second]+w[i])
            {
                dis[j]=dis[t.second]+w[i];
                fs[j]=fs[t.second]+fj[j];
                q.push({dis[j],j});

            }
            else if(dis[j]==dis[t.second]+w[i])
            {
                 fs[j]=max(fs[j],fs[t.second]+fj[j]);
            }

        }
    }

}


int main()
{
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++)cin>>fj[i];

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }



    dj(start);

    cout<<dis[end]<<" "<<fs[end]<<endl;

}