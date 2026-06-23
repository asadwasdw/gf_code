#include<bits/stdc++.h>
//#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


int a[N][N];
ll dp[N][N];

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        a[x][y]=1;
    }

    ll ans = 0;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1){
                dp[i][j]=0;
            }
            else 
            {
                dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }

            ans+=dp[i][j];
        }
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