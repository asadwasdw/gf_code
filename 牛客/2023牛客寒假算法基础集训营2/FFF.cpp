#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N=5e5+10;

const int INF=-1;
int f1[N][4];
int f2[N][4];
  int n,m;

 void bfs1(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    while(q.size())
    {
        
        int X=q.front().first;
        int Y=q.front().second;
        q.pop();
        if(Y!=3&&f1[X][Y+1]==0){

            q.push({X,Y+1});
            f1[X][Y+1]=1;
        }

        if(X!=n&&f1[X+1][Y]==0){
            q.push({X+1,Y});
            f1[X+1][Y]=1;
        }
    }
}

void bfs2(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    while(q.size())
    {
        
        int X=q.front().first;
        int Y=q.front().second;
        q.pop();
        if(Y!=1&&f2[X][Y-1]==0){

            q.push({X,Y-1});
            f2[X][Y-1]=1;
        }

        if(X!=1&&f2[X-1][Y]==0){
            q.push({X-1,Y});
            f2[X-1][Y]=1;
        }
    }
}

void solve()
{
   
    cin>>n>>m;
    
    for(int i=1;i<=m;i++)
    {
        int x=0;
        int y=0;
        cin>>x>>y;
        if(f1[x][y]!=INF)f1[x][y]=f2[x][y]=INF;
        else f1[x][y]=f2[x][y]=0;
    }
    bfs1(1,1);
    bfs2(n,3);
    int ans=0;
    f2[n][3]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++)
        {
            //cout<<f1[i][j]<<" ";
             if(f1[i][j]==1&&f2[i][j]==1)ans++;
             f1[i][j]=f2[i][j]=0;
        }
  //    cout<<endl;
       
    }
    cout<<ans<<endl;

}

int main()
{
    int  t;cin>>t;while (t--)
    {
        solve();
    }
    


}