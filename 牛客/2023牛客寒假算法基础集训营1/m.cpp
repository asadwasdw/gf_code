#include<iostream>
#include<algorithm>

using namespace std;

const int N=510;

double dp[N][N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][k]+(double)(j-k)/(m-k));
            }
        }
    }

    double ans=0;
    for(int i=1;i<=m;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    printf("%.12llf",ans);
 


}