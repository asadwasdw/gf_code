#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>

using namespace std;
const int mod = 998244353;

int n,m;
const int N=510;
int a[N][N];
int dist[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
typedef pair<int,int>PII;
void bfs()
{
    deque<PII>q;
    memset(dist,0x3f,sizeof dist);
    dist[1][1]=0;
    q.push_back({1,1});

    while(q.size())
    {
        
        auto t=q.front();
        q.pop_front();
        //cout<<t.first<<" "<<t.second<<endl;

        for(int k=0;k<4;k++)
        {
            int d=dist[t.first][t.second];
            int x=t.first+dx[k];
            int y=t.second+dy[k];
            if(x<1||x>n||y<1||y>m)continue;
            if(a[x][y]=='.')
            {
                if(dist[x][y]>d){
                    dist[x][y]=d;
                    q.push_front({x,y});
                }
            }
            else{
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        int xx=x+i;
                        int yy=y+j;
                        //if(x==2&&y==2)cout<<t.first<<" "<<t.second<<endl;

                        if(xx<1||xx>n||yy<1||yy>m)continue;
                        if(dist[xx][yy]>d+1)
                        {
                        dist[xx][yy]=d+1;
                        q.push_back({xx,yy});
                        }
                    }
                }
            }


        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char t;
            cin>>t;
            a[i][j]=t;
        }

    bfs();

    // for(int i=1;i<=n;i++){
    // for(int j=1;j<=m;j++)
    // {
    //     cout<<dist[i][j]<<" ";
    // }
    // cout<<endl;
    // }
    cout<<dist[n][m];
}
