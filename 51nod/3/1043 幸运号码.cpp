#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e4+10;

int dp[1010][N];

#define int long long 

const int MOD =1e9+7;

signed main()
{
    int n;cin>>n;
    dp[0][0]=1;
    for(int i=0;i<=9;i++)
    {
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9*i;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(j-k<0)break;

                dp[i][j]+=dp[i-1][j-k];

                dp[i][j]%=MOD;
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
    }

    int ans=0;

    for(int j=1;j<=9*n;j++)
    {

        ans+= dp[n][j]*(dp[n][j]-dp[n-1][j]+MOD)%MOD;
        ans%=MOD;

    }

    cout<<ans<<endl;

}