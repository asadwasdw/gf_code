#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<queue>

using namespace std;

const int N=310;

int n,m,k;

char a[N][N];
int dis[N][N];

int jl[25][25];


typedef pair<int,int>PII;

PII d[25];
map<PII,int>zd;

int cnt=0;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int dp[262144*2*2*2*2][25];



void bfs(int u)
{
    int x=d[u].first;
    int y=d[u].second;

    memset(dis,0x3f,sizeof dis);

    dis[x][y]=0;

    queue<PII>q;
    q.push({x,y});

    while(q.size())
    {
        auto t=q.front();q.pop();

        for(int i=0;i<4;i++)
        {
            x=t.first+dx[i];
            y=t.second+dy[i];

            if(x<1||x>n||y<1||y>m)continue;

            if(a[x][y]=='#')continue;
            if(dis[x][y]!=0x3f3f3f3f)continue;

            dis[x][y]=dis[t.first][t.second]+1;
         //   cout<<zd[{x,y}]<<endl;
            if(zd[{x,y}])
            {
                jl[u][zd[{x,y}]]=dis[x][y];
            }

            q.push({x,y});

        }
        
    }
}

int js(int x)
{
    int res=0;
    while(x)
    {
        res++;
        x-= x&-x ;
    }
    return res;
}

int ans=0;

void bfs2()
{
   // cout<<cnt<<endl;

    queue<PII>q;
 
    memset(dp,0x3f,sizeof dp);

    dp[0][19]=0;

    q.push({0,19});

    while(q.size())
    {
        int zt=q.front().first;
        int wz=q.front().second;

        q.pop();

        if(dp[zt][wz]+jl[wz][20]<=k)
        {
            
            //cout<<wz<<endl;

            ans=max(js(zt),ans);

        //  cout<<wz<<" "<<zt<<" "<<dp[zt][wz]<<" "<<jl[wz][20]<<" "<<ans<<endl;
         }


        for(int i=1;i<=cnt;i++)
        {
            if(((zt>>i)&1)!=0)continue;
            
            int xdzt=zt + ( 1<<i );

            //cout<<zt<<" "<<xdzt<<endl;


            if(dp[xdzt][i]>dp[zt][wz]+jl[wz][i])
            {
                dp[xdzt][i]=dp[zt][wz]+jl[wz][i];
                q.push({xdzt,i});
            }


            if(dp[xdzt][i]+jl[i][20]<=k)
            {
                ans=max(js(xdzt),ans);
            }
        }
    }
}




int main()
{

    cin>>n>>m>>k;

    memset(jl,0x3f,sizeof jl);


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            //cout<<t<<endl;
            a[i][j]=t;

            if(t=='S'){
                d[19]={i,j};
                zd[{i,j}]=19;
              //  cout<<i<<" "<<j<<endl;
            }
            else if(t=='G')
            {
                d[20]={i,j};
                zd[{i,j}]=20;
                // cout<<i<<" "<<j<<endl;
            }
            else if(t=='o')
            {
                d[++cnt]={i,j};
                zd[{i,j}]=cnt;
            }
        }
    }


    // bfs(1);

    
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<dis[i][j]<<" ";
    //     cout<<endl;
    // }

    bfs(19);
    bfs(20);

    for(int i=1;i<=cnt;i++)
    {
        bfs(i);
    }
    //cout<<jl[19][20]<<endl;

    //for(int i=1;i<=cnt;i++)cout<<d[i].first<<" "<<d[i].second<<endl;

    // for(auto t:zd)
    // {
    //     cout<<t.first.first<<" "<<t.first.second<<" "<<t.second<<endl;
    // }


    // for(int i=1;i<=20;i++)
    // {
    //     for(int j=1;j<=20;j++)cout<<jl[i][j]<<" ";
    //     cout<<endl;
    // }

    if(jl[19][20]>k)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    // bfs2();

    memset(dp,0x3f,sizeof dp);

    for(int i=1;i<=cnt;i++)
    {
        int xdzt= 1<<i;

        dp[xdzt][i]=jl[19][i];
    
    }



    for(int zt=0;zt<1<<19;zt+=2)
    {
        
        for(int i=1;i<=cnt;i++)
        {
            if((zt>>i)&1)continue;

            for(int j=1;j<=cnt;j++)
            {
                if((zt>>j)&1==0)continue;

                int xdzt=zt + ( 1<<i );

                if(dp[xdzt][i]>dp[zt][j]+jl[i][j])
                {
                    dp[xdzt][i]=dp[zt][j]+jl[i][j];
                }
                if(dp[xdzt][i]+jl[i][20]<=k)ans=max(js(xdzt),ans);
            
            }
        }

    }


    cout<<ans<<endl;

    
}