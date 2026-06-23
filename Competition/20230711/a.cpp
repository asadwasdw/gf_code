#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=5050;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll st[N*N];

void init()
{
    st[0]=1;
    for(int i=1;i<=5010*5010;i++)
    {
        st[i]=i*st[i-1]%mod;
    }
}

void solve()
{ 
    ll n;
    cin>>n;
    ll ans=0;

    vector<vector<ll>>dp(n+10,vector<int>(n+10,0));
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++){

            dp[i][j]+=dp[i-1][j]*(n*j-i+1)%mod;
            dp[i][j]+=dp[i-1][j-1]*(n-j+1)%mod*n%mod;
            dp[i][j]%=mod;

           // ans+=j*dp[i][j];
        }
    }
    //cout<<jc(9)<<endl;

    // for(int i = 1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";cout<<endl;
    // }

   // cout<<dp[n][n]<<endl;

    for(int i = 1;i<=n;i++)ans=(ans+dp[n][i]%mod*i%mod)%mod;
    //cout<<ans<<endl;
    cout<<(ans*st[n*(n-1)]%mod)<<endl;
}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}