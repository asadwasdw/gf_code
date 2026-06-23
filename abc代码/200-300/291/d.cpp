#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10,mod=998244353;
int a[N],b[N];
long long dp[N][3];
int main()
{
    int n;cin>>n;

    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }

    dp[1][1]=1;dp[1][0]=1;

    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])dp[i][0]+=dp[i-1][0];
        if(a[i]!=b[i-1])dp[i][0]+=dp[i-1][1];
        if(b[i]!=b[i-1])dp[i][1]+=dp[i-1][1];
        if(b[i]!=a[i-1])dp[i][1]+=dp[i-1][0];

        dp[i][1]%=mod;
        dp[i][0]%=mod;

    }

    cout<<(dp[n][1]+dp[n][0])%mod<<endl;
    
}