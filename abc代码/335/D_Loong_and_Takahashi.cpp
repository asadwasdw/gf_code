#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[50][50];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n;

void dfs(int x,int y,int now,int num){

    // cout<<x<<" "<<y<<endl;

    if(num== n*n){
        return;
    }
    int tx=x+dx[now];
    int ty=y+dy[now];

    if(a[tx][ty]!=0){
        now=(now+1)%4;
    }
    tx=x+dx[now];
    ty=y+dy[now];

    a[tx][ty]=num;
    dfs(tx,ty,now,num+1);


}

void solve()
{
    memset(a,-1,sizeof a);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)a[i][j]=0;
    a[1][1]=1;


    dfs(1,1,0,2);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            
            if(a[i][j]==0)cout<<"T ";
            else cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}