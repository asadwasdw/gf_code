#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[110][110];
int b[110][110];

int cnt =0;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
   int n;

void dfs(int x,int y,int t)
{

   
    int tx = x+dx[cnt];
    int ty = y+dy[cnt];

    if(tx<1||tx>n||ty<1||ty>n)cnt++;

    if(cnt >= 4)return ;

     tx = x+dx[cnt];
     ty = y+dy[cnt];
 //cout<<tx<<" "<<ty<<endl;

    dfs(tx,ty,a[x][y]);
    a[x][y]=t;

}

void solve()
{
 cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char t;
            cin>>t;
            if(t=='1')a[i][j]=1;
        }
    }

    dfs(1,1,a[2][1]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<a[i][j];cout<<endl;
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