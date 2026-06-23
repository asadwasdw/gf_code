
#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e5+10,P=31,MOD = 998244353;

long long a[2*N];
long long p[2*N];
long long h[2*N];
long long dp[2*N];

int zh(char a)
{
    if(a=='a')return 1;
    if(a=='e')return 2;
    if(a=='h')return 3;
    if(a=='n')return 4;
    return 0;
}

long long get(int l,int r)
{
    return h[r]-h[l]*p[r-l+1];
}

long long f(int x,int y)
{
    return (h[y]-h[x]*p[y-x]%MOD+MOD)%MOD;
}

// long long f(int x,int y)//从x+1到y的hash 
// {return (h[y]-h[x]*p[y-x]%MOD+MOD)%MOD;}
 


int main()
{
    int n;
    p[0]=1;
    string T;
    cin>>T;
    n=T.size();
    for(int i=1;i<=n;i++)
    {
        char t;
       t=T[i-1];
        a[i]=zh(t);
        p[i]=p[i-1]*P%MOD;
        h[i]=h[i-1]*P%MOD+a[i];
    }

    for(int i=1;i<=min(n,15);i++)
	{
		h[n+i]=h[n+i-1]*P%MOD;
        h[i+n]+=a[i];
	}

    // for(int i=1;i<=2*n;i++)
    // {
    //     cout<<i<<" "<<h[i]<<endl;
    // }

    long long ans=0;
    int s=n;

	// for(int i=1;i<=min(15,s);i++)
	// {
	// 	dp[i-1]=0;
	// 	for(int j=i;j<=i+6;j++)
	// 		dp[j]=f(i-1,j);
	// 	for(int j=i+7;j<=s+i-1;j++)
	// 	{
	// 		dp[j]=dp[j-1]+f(j-1,j);
	// 		for(int k=max(j-15,i-1);k<j-1;k++)
	// 			dp[j]=max(dp[j],dp[k]+f(k,j));
	// 	}
	// 	ans=max(ans,dp[s+i-1]);
	// }


    for(int i=1;i<=min(15,n);i++)
    {
        dp[i-1]=0;

        for(int j=i;j<=i+6;j++)
           dp[j]=f(i-1,j);
        
        for(int j=i+7;j<=s+i-1;j++)
        {
            dp[j]=dp[j-1]+f(j-1,j);
            for(int k=max(j-15,i-1);k<j-1;k++)
            {
                dp[j]=max(dp[j],dp[k]+f(k,j));
            }
        }
        ans=max(dp[i+n-1],ans);
    }
	printf("%lld",ans);

}