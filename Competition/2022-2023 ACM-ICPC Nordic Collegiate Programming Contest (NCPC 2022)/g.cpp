#include<iostream>
#include<algorithm>

using namespace std;

const int N=5010;

double dp[N][N];

double p[N];

int main()
{

    int n,k;cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }

    sort(p+1,p+n+1,greater<double>());

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    double ans=0;

    for(int i=1;i<=n;i++)
    {
        double res=0;
        for(int j=1;j<=i;j++)
        {
               int ct=i-j;
               if(j-ct<k)continue;
               //cout<<i<<" "<<j<<endl;
               res+=dp[i][j];
        }
        ans=max(res,ans);
    }

    cout<<ans<<endl;

}