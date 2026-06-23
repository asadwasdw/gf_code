#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

char a[N][N];


void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            a[i][j]=t;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='#'){
                //if(i+1<=n)
                    a[i+1][j]='#';
                //if(i+1<=n&&j+1<=m)
                    a[i+1][j+1]='#';
            }
        }
    }


    // for(int i=1;i<=n+1;i++){   
    //     for(int j=1;j<=m+1;j++)cout<<a[i][j]<<" ";cout<<endl;
    // }
    
    vector<ll>dp(n+10,0);
    dp[n+1]=1;

    for(int i=1;i<=m;i++)
    {
        vector<ll>dp2(n+10,0);
        ll sum = 0;
        for(int j = n+1;j;j-- )
        {
            sum+=dp[j];
            sum%=mod;
            if(a[j-1][i]=='#')continue;
            dp2[j]=dp[j-1]+sum;
            dp2[j]%=mod;
        }
        swap(dp,dp2);
        //for(int j=1;j<=n+1;j++)cout<<dp[j]<<" ";cout<<endl;
    }

    ll ans = 0;
    for(int i=1;i<=n+1;i++)ans+=dp[i],ans%=mod;
    cout<<ans%mod<<endl;

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