#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 0x3f3f3f3f;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,k;

typedef pair<int,int> PII;


bool check(int x,int y)
{
    if(x<1||x>n||y<1||y>m)return false;
    return true;
}


int bfs(int x1,int y1,int x2,int y2)
{
    
    vector<vector<char>>a(n+10,vector<char>(m+10));
    vector<vector<int>> d (n+10,vector<int>(m+10,INF));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
           cin>>a[i][j];
        }
    }

    if(x1==x2&&y1==y2)return 0;

    queue<PII>q;
    q.push({x1,y1});
    d[x1][y1]=0;


    while(q.size())
    {

        auto T=q.front();q.pop();
       // cout<<T.first<<" "<<T.second<<endl<<"------>"<<endl;
        for(int i=0;i<4;i++)
        {
            for(int j=1;j<=k;j++)
            {
                int x=T.first+dx[i]*j;
                int y=T.second+dy[i]*j;
                
                if(!check(x,y))break;
                if(a[x][y]=='@')break;
                //if(d[x][y]<d[T.first][T.second]+1)break;

               if(d[x][y]!=INF)break;

               if(d[x][y]>d[T.first][T.second]+1){
                  d[x][y]=d[T.first][T.second]+1;
                   q.push({x,y});
               }
              
               // cout<<x<<" "<<y<<endl;
               
            }
        }
    }

    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            cout<<d[i][j]<<" "; 
        }
        cout<<endl;
    }


    if(d[x2][y2]==INF)return -1;
    return d[x2][y2];


}




int main()
{
   
    cin>>n>>m>>k;
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<bfs(x1,y1,x2,y2)<<endl;

}