#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef pair<int,int>PII;
const int N=15;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

unordered_map<int,bool>st;

int a[N][N];
 int n,m;
int ans=0;
void dfs(int x,int y)
{

    if(x==n&&y==m)
    {
        ans++;
        return;
    }

    if(x!=n&&!st[a[x+1][y]])
    {
        st[a[x+1][y]]=true;
        dfs(x+1,y);
         st[a[x+1][y]]=false;
    }

    if(y!=m&&!st[a[x][y+1]])
    {
        st[a[x][y+1]]=true;
        dfs(x,y+1);
         st[a[x][y+1]]=false;
    }

}

void solve()
{
   
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    st[a[1][1]]=true;
    dfs(1,1);
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