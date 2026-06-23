#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int g[110][110];

void solve()
{
    int n,m;cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
   for(int i=1;i<=n;i++)g[i][i]=0;

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
         //   cout<<g[i][j]<<" ";
            ans=max(g[i][j],ans);
        }//cout<<endl;
    }

    cout<<ans<<endl;








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