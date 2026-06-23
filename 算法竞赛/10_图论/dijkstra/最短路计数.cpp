#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 4e6+10;

typedef long long  ll;

ll dis[N];
ll cnt[N];
bool st[N];

int h[N],idx,e[N],ne[N],w[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

typedef pair<ll,ll>PII;
//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1144


int main()
{

    int n,m;cin>>n>>m;

    memset(h,-1,sizeof h);
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b,1);
        add(b,a,1);
    }

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    cnt[1]=1;

    while(q.size())
    {
        PII t=q.top();q.pop();
        if(st[t.second])continue;
        st[t.second]=true;

        for(int i=h[t.second];i!=-1;i=ne[i])
        {
            int j=e[i];
            int z=w[i];   
            //cout<<j<<endl;
            if(dis[j]>dis[t.second]+z)
            {
                cnt[j]=cnt[t.second];
                dis[j]=dis[t.second]+z;
                q.push({dis[j],j});
            }
            else if(dis[j]==dis[t.second]+z)
            {
                cnt[j]+=cnt[t.second];
                cnt[j]%=100003;
            }
        }
    }

    for(int i=1;i<=n;i++)cout<<cnt[i]%100003<<endl;




}