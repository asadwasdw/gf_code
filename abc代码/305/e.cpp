#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N =4e6+10;

int h[N],e[N],ne[N],idx;
int n,m,Q;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
typedef pair<int,int>PII;

priority_queue<PII>q;

int dist[N];

bool st[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin>>n>>m>>Q;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    for(int i=1;i<=Q;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        dist[a]=max(dist[a],b);
        q.push({b,a});
        //cout<<"Sss"<<a<<" "<<b<<endl;
    }


    while(q.size())
    {
        auto t =q.top();q.pop();
        // if(st[t.second])continue;
        // st[t.second]=true;

       cout<<t.second<<" "<<t.first<<endl;

        for(int i=h[t.second];~i;i=ne[i])
        {
            int j = e[i];
    //    cout<<j<<" ";
            if(dist[j]>=t.first)continue;
            if(t.first==1)continue;
            //if(dist[j])continue;
            q.push({t.first-1,j});
            dist[j]=t.first-1;
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i])cnt++;
    }
    cout<<cnt<<endl;

    for(int i=1;i<=n;i++)
    {
        if(dist[i])cout<<i<<" ";
    }

    
}