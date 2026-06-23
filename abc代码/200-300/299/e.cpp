#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int n,m;
const int N=4020;
int dis[N][N];

typedef pair<int,int>PII;

int h[N],ne[N*2],e[N*2],idx;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void bfs(int x)
{

    dis[x][x]=0;

    queue<int>q;
    q.push(x);

    while(q.size())
    {
        int t=q.front();q.pop();

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dis[x][j]!=0x3f3f3f3f)continue;
            dis[x][j]=dis[x][t]+1;
            q.push(j);
        }
    }


}

int color[N];
PII yq[N];

void solve()
{
    memset(dis,0x3f,sizeof dis);
    memset(h,-1,sizeof h);

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        
        add(a,b);
        add(b,a);
    }

  //  bfs(1);

    for(int i=1;i<=n;i++)
    {
       bfs(i);
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
    //     cout<<endl;
    // }

    int q;cin>>q;

    for(int i=1;i<=q;i++)
    {
        int a,b;cin>>a>>b;

        yq[i]={a,b};

        for(int j=1;j<=n;j++)
        {
           if(dis[a][j]<b)color[j]=2;
        }
    }

   // for(int i=1;i<=n;i++)cout<<color[i]<<" ";

    bool ky=true;

    for(int i=1;i<=q&&ky;i++)
    {
        int a=yq[i].first;
        int b=yq[i].second;

        bool zd=false;
        for(int j=1;j<=n;j++)
        {
            
            if(dis[a][j]==b&&color[j]==0)
            {
                zd=true;
               // cout<<j<<endl;
               // color[j]=1;
            }

        }

        if(!zd)
        {
            ky=false;
        }
    }

    if(ky){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==2)cout<<"0";
            else cout<<"1";
        }
    }
    else cout<<"No"<<endl;
    

}

int main()
{
   // int t=1;cin>>t;while(t--)
    solve();
    return 0;
}