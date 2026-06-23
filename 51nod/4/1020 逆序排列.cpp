#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010,M=2e4+10;
typedef long long ll;

int dp[N][M];
const int MOD=1e9+7;

void init(ll n,ll m)
{
    for(ll i=1;i<=n;i++)
    {
        dp[i][0]=1;
    }

    for(ll i=2;i<=n;i++)
    {
        for(ll j=1;j<=m&&j<=i*(i+1)/2;j++)
        {
            dp[i][j]=((ll)dp[i-1][j]+dp[i][j-1])%MOD;
            if(j>=i)
            {
                dp[i][j]=((ll)dp[i][j]-dp[i-1][j-i]+MOD)%MOD;
            }
        }
    }

}


int main()
{
    init(1000,20000);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<dp[n][m]%MOD<<endl;
    }
 




}