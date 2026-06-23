#include<bits/stdc++.h>
using namespace std;
int T;
int N,M;
int a[20][20];
int vis[20][20];
int ans=0;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y,int sum){
    // cout << x << " " << y << endl;
    if(x==N +1){ // 1
    	ans=max(ans,sum);
        return;
    }
    int nextX=x;
    int nextY=y+1;
    if (nextY==M + 1){ // 3
        nextX=x+1;
        nextY=1;
    }
    dfs(nextX,nextY,sum);
    if(vis[x][y]==0){
        sum+=a[x][y];
        vector<pair<int, int>> zuobiao;
        for(int i=0;i<8;i++){ // 2
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1 && nx<=N && ny>=1 && ny<=M){
                vis[nx][ny]++;
                zuobiao.push_back({nx,ny});
            }
        }
        dfs(nextX,nextY,sum);
        sum-=a[x][y];
        for(auto& xy : zuobiao){
            vis[xy.first][xy.second]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>a[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(1,1,0);
        cout<<ans<<endl;
    }
    return 0;
}