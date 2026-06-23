#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
 int n,m;
const int M=1e5+10;

 int h[M],ne[M],e[M],idx;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

const int N=10;

int dis[N];
int jl[85][85];



void floyd()
{

    for(int i=1;i<=n;i++)jl[i][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                jl[i][j]=min(jl[i][k]+jl[k][j],jl[i][j]);
            }
        }
    }
}

void bfs(int u)
{
    queue<int>q;

    q.push(u);

    memset(dis,0x3f,sizeof dis);

    dis[u]=0;

    jl[u][u]=0;

    while(q.size())
    {

        int t=q.front();q.pop();

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];

            if(dis[j]!=0x3f3f3f3f)continue;

            dis[j]=dis[t]+1;

            jl[u][j]=dis[j];

            q.push(j);
        }
    }

}

int f[N][N][N][N][N];

int a[85];


int main()
{
   cin>>n>>m;

   memset(h,-1,sizeof h);
   memset(jl,0x3f,sizeof jl);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        jl[a][b]=1;
    }

    for(int i=1;i<=n;i++)
    {
        bfs(i);
    }

    int num;
    cin>>num;

    for(int i=1;i<=num;i++)cin>>a[i];
    a[1]=1;


   //floyd();

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<jl[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"Ssssssss"<<endl;

    memset(f,0x3f,sizeof f);


    f[0][1][0][1][0]=0;

    for(int i=1;i<=num;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=n;k++)
                for(int l=1;l<=n;l++)
                    for(int r=0;r<=n;r++)
                    {
                        int t=(jl[a[i]][a[i-1]]);

                        if(j==a[i]&&k>=t)
                        {
                            f[i][j][k][l][r]=min(f[i-1][a[i-1]][k-t][l][r]+t,f[i][j][k][l][r]);
                        }

                        if(l==a[i]&&r>=t)
                        {
                             f[i][j][k][l][r]=min(f[i-1][j][k][a[i-1]][r-t]+t,f[i][j][k][l][r]);
                        }
                    }

            int ans=0;


        for(int j=1;j<=n;j++)
            for(int k=0;k<=n;k++)
                for(int l=1;l<=n;l++)
                    for(int r=0;r<=n;r++)
                    {
                        if(f[num][j][k][l][r]!=0x3f3f3f3f)
                        {
                            ans=min(max(k,r),ans);
                        }
                    }

               cout<<ans<<endl;     

}