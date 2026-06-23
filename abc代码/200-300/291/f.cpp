#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int n,m;

const int N=5e6+10;
int h[N],ne[N],e[N];
int idx;
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dis[N];

void bfs()
{
    queue<int>q;
    q.push(n);

    memset(dis,0x3f,sizeof dis);
    dis[n]=0;

    while(q.size())
    {
        int t=q.front();
        q.pop();

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];

            if(dis[j]!=0x3f3f3f3f)continue;
            q.push(j);
            dis[j]=min(dis[j],dis[t]+1);
            
        }
    }

}

int dis1[N];
string s[N];


int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    memset(dis1,0x3f,sizeof dis1);

   dis1[1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];

        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='1')
            {
                add(i+j+1,i);
                dis1[i+j+1]=min(dis1[i+1+j],dis1[i]+1);
            }
        }
    }


    bfs();

   // for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;

    for(int i=2;i<n;i++)
    {
        int ans=0x3f3f3f3f;

        for(int j=max(1,i-m);j<i;j++)
        {

            for(int k=0;k<m;k++)
            {
                if(s[j][k]=='0')continue;

                int t = j+k+1;
                if(t<=i)continue;

                ans=min(ans,dis1[j]+dis[t]+1);
            }

        }

        if(ans>=0x3f3f3f3f/2)ans=-1;

        cout<<ans<<" ";
    }

}