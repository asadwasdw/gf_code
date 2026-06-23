#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll dp[N][N];
//double dp[N][N];


ll qmi(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res%c;
}


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    dp[0][0]=1;

    //if(dp[0][1])cout<<"s"<<endl;

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!dp[i][j])continue;
            //cout<<i<<" "<<j<<endl;

            for(int z=1;z<=m;z++)
            {
                
                int t = j + z;
                //cout<<t<<" "<<z<<endl;
                if(t>n)
                {
                    t = n-(t-n);
                }
                //cout<<t<<" "<<z<<endl;

                dp[i+1][t] += dp[i][j]*qmi(m,mod-2,mod)%mod;
                dp[i+1][t] %= mod;
                //dp[i+1][t] = dp[i][j]*(1.0/m);
            }
        }
    }

    ll ans =0;

    for(int i=0;i<=k;i++)
    {
        ans+=dp[i][n];
        ans%=mod;
    }
    //cout<<dp[k][n]<<endl;
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