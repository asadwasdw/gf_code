#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

int st[N];

int jd(int t)
{
    t=max(10,t);
    t=min(300,t);
    return t;
}


void bfs()
{
    queue<PII>q;
    q.push({10,0});
    st[10]=0;

    while(q.size())
    {
        PII t=q.front();
        q.pop();

        int T=t.first+1;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }

        T=t.first-1;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }

        T=t.first+10;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }
        T=t.first-10;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }

         T=t.first+100;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }
        T=t.first-100;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }

        T=300;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }
        T=10;
        T=jd(T);
        if(st[T]==-1)
        {
            st[T]=t.second+1;
            q.push({T,st[T]});
        }
        
    }
    
}


void solve()
{
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        int x;cin>>x;
       // cout<<st[x]<<endl;
        ans+=st[x];
    }
    cout<<ans<<endl;
}



signed main()
{
    memset(st,-1,sizeof st);
    bfs();
    
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
    int t;cin>>t;while(t--)
    solve();
}