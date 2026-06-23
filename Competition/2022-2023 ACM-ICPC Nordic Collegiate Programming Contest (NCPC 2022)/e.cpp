#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

const int INF =0x3f3f3f3f;
const int N=2e4+10;

int dis[N];
int k=INF;
int n,m;
int h[N],ne[N],e[N],idx;
int f[N];

bool st[N];
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

struct e
{
    int l,r;
}edge[6010];


void bfs(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[s]=0;
    f[s]=-1;
    queue<int>q;
    q.push(s);
    st[s]=true;

    while(q.size())
    {

        auto t = q.front();
        //cout<<t<<endl;
        q.pop();

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(st[j])
            {
                if(j!=f[t])k=min(k,dis[j]+dis[t]+1);
               // cout<<j<<" "<<k<<endl;
                continue;
            }
            f[j]=t;
            st[j]=true;
            dis[j]=dis[t]+1;
            q.push(j);
        }
    }
}


int bfs2(int bs,int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[s]=0;
    vector<int>num(n+1,0);
    //cout<<"bs "<<bs<<endl;

    queue<int>q;
    q.push(s);
    st[s]=true;
     f[s]=-1;
    while(q.size())
    {

        auto t = q.front();
        //cout<<t<<" "<<dis[t]<<endl;
        q.pop(); 

        for(int i = h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(j==f[t])continue;

            if(dis[t]==bs-1)
            {
                num[j]++;
                continue;
            }

            if(st[j])continue;
            st[j]=true;
            dis[j]=dis[t]+1;
            q.push(j);
            f[j]=t;
        }
    }

    int res=0;

    for(int i=1;i<=n;i++)
    {
        if(num[i]){
        res+=num[i]*(num[i]-1)/2;
       // cout<<i<<" "<<num[i]<<endl;
        }
    }

    return res;


}

int bfs3(int bs,int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[s]=0;
    vector<int>num(n+1,0);
    //cout<<"bs "<<bs<<endl;

    queue<int>q;
    q.push(s);
    st[s]=true;
    f[s]=-1;
    vector<bool>yl(n+1,false);
    while(q.size())
    {

        auto t = q.front();
        //cout<<t<<" "<<dis[t]<<endl;
        q.pop(); 

        for(int i = h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(j==f[t])continue;

            if(dis[t]==bs-1)
            {
                yl[j]=true;
                continue;
            }

            if(st[j])continue;
            st[j]=true;
            dis[j]=dis[t]+1;
            q.push(j);
            f[j]=t;
        }
    }

    int res=0;

    for(int i=1;i<=m;i++)
    {
        if(yl[edge[i].l]&&yl[edge[i].r])res++;
    }
    return res;

}


int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        
        cin>>a>>b;
        add(a,b);
        add(b,a);
        edge[i]={a,b};
    }

    for(int i=1;i<=n;i++) bfs(i);
  //  cout<<k<<endl;

    if(k%2==0)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=bfs2(k/2,i);
        }
        ans/=k;
        cout<<ans<<endl;
    }
    else 
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=bfs3(k/2,i);

        }
        ans/=k;
        cout<<ans<<endl;





    }




}

