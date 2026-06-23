#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=300+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dp[N][N][N];
unordered_map<ll,bool>st;
void solve()
{
    int n,m;
    int x1,y1,x2,y2,x3,y3;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        st[x*mod+y]=true;
    }


    dp[0][0][0]=1;

    ll ans = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=i;k++)
            {
                int z = i-k-j;
                if(z<0)continue;

                int x = k*x1+j*x2+z*x3;
                int y = k*y1+j*y2+z*y3;
                //cout<<x<<" "<<y<<endl;
                if(st[x*mod+y])continue;

                if(j!=0)dp[i][j][k]+=dp[i-1][j-1][k];
                if(k!=0)dp[i][j][k]+=dp[i-1][j][k-1];
                if(z!=0)dp[i][j][k]+=dp[i-1][j][k];

                dp[i][j][k]%=mod;

                if(i==n)ans+=dp[i][j][k];
                ans%=mod;
               // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
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