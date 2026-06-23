#include<iostream>
#include<algorithm>
#include<cmath>
//#define int long long
using namespace std;
typedef long long ll;
const int N=1e6+10,MOD=1e9+7;

int f[N];
int g[N];
int dp[22][N];

signed main()
{
	int n,m;
	cin>>n>>m;
	
	int len=log2(n)+1;
	dp[1][1]=1;
	f[0]=1;
	
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=((ll)dp[i][j]+dp[i][j-1])%MOD;
			if(j*2<=n)
			{
				dp[i+1][j*2]=((ll)dp[i+1][j*2]+dp[i][j])%MOD;
			}
			else
			{
				//cout<<dp[i][j]<<endl;
				g[i]=((ll)g[i]+dp[i][j])%MOD;
			}
		}
	}

	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" "<<g[i]<<endl;
	// }
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=len&&j<=i;j++)
		{
			f[i]=((ll)f[i]+(ll)f[i-j]*g[j])%MOD;
			//cout<<g[j]<<endl;
		}
	}
	
	cout<<f[m]<<endl;
}