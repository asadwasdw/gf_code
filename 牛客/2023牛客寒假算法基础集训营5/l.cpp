#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;
const long long N=2e5+10,INF=9223372036854775000;
long long dp[N];

long long w[N],v[N];

int main()
{
    int n,m;
    cin>>n>>m;


    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        dp[i]=INF;
    }

    dp[n]=0;

    for(int i=n;i>=3;i--)
    {
        if(dp[i]==INF)continue;
        //cout<<i<<endl;
        for(int j=1;j<=m;j++)
        {
            if(w[j]>=i)continue;
            int bh=i-(i%w[j]);
            dp[bh]=min( dp[i]+v[j], dp[bh]);
        }

    }



    for(int i=1;i<=n;i++)
     {
         if(dp[i]!=INF)
         {
            cout<<dp[i]<<endl;
            return 0;
         }
     }

  //  cout<<dp[2]<<endl;


}