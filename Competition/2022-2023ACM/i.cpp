#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


int n,m;
int a[N][N];


int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool st[N][N];
int bfs(int X,int Y)
{
    queue<PII>que;
    memset(st,0,sizeof st);
   
    st[X][Y]=true;
    que.push({X,Y});

    int res=0;
    while(que.size()){
        res++;
        PII t=que.front();que.pop();
        int x=t.first;
        int y=t.second;

        for(int i=0;i<4;i++)
        {
            X=x+dx[i];
            Y=y+dy[i];
             
            if(st[X][Y])continue;
            if(X<1||X>n||Y<1||Y>m)continue;
             
            if(a[X][Y]<a[x][y])continue;
            st[X][Y]=true;
            que.push({X,Y});
           // cout<<X<<Y<<endl;
        }
    }

    return res;

}



void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;


    //cout<<bfs(1,5);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=max(bfs(i,j),ans);
        }
    }
    cout<<ans<<endl;




}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}