#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=110+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int g[N][N];
int cnt[N][N];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           // if(i!=j)
            g[i][j]=INF;
        }
    }


    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
        cnt[a][b]=cnt[b][a]=1;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++){
                if(k==i||k==j||i==j)continue;
                if(g[i][j]==g[i][k]+g[k][j]){
                    cnt[i][j]+=cnt[i][k]*cnt[k][j];
                }
                else if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                    cnt[i][j]=cnt[i][k]*cnt[k][j];
                }
            }
        }
    }


    for(int u=1;u<=n;u++){
        double ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++){
                //if(cnt[i][j]==0)continue;
                if(g[i][j]==g[i][u]+g[u][j]){
                    ans+=(1.0*cnt[i][u]*cnt[u][j])/cnt[i][j];
                }
            }
        }
         printf("%.3lf\n",ans);
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