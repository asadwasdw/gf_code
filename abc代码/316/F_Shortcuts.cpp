#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int jc(int x)
{
    if(x<=0)return 0;
    else return pow(2,x-1);
}
PII d[N];

double js(int i,int j)
{
    double x = d[i].first-d[j].first;
    double y = d[i].second-d[j].second;
    return sqrt(x*x+y*y);
}

double dp[N][40];
int a[N];
int b[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i].first>>d[i].second;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<40;j++)dp[i][j]=INF;
    }

    dp[1][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j = 0;j<30;j++)
        {
            for(int x = i+1;x<=n&&j+x-i-1<30;x++){
                dp[x][j+x-i-1]=min(dp[x][j+x-i-1],dp[i][j]+js(i,x));
            }
        }
    }
    double ans = INF;
    for(int i=0;i<30;i++)
    {
        ans=min(ans,dp[n][i]+jc(i));
       // cout<<dp[n][i]<<" "<<jc(i)<<endl;
    }
    printf("%.15lf",ans);
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