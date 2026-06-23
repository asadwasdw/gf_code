#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int h[N],e[N],ne[N],idx,w[N];
int dist[N];
bool st[N];
typedef pair<int,int>PII;
void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}


void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});

    dist[1]=0;

    while(q.size())
    {
        PII t=q.top();q.pop();

        if(st[t.second])continue;
        st[t.second]=true;
       // cout<<"S"<<endl;
        for(int i=h[t.second];i != -1;i=ne[i])
        {

            int j=e[i];
            int c=w[i];
            //cout<<j<<endl;
            if(st[j])continue;
            if(dist[j]>dist[t.second]+c)
            {
                dist[j]=dist[t.second]+c;
                q.push({dist[i],j});
            }

        }
    }
}

int main()
{
    while(1)
    {
    int n,m;
    cin>>n>>m;
    if(n==m&&n==0)break;

    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
//   cout<<h[2]<<endl;

    dijkstra();

    cout<<dist[n]<<endl;
    }

}
