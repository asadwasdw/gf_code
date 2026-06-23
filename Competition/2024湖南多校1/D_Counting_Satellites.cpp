#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k;
	cin>>k;
	string s0="SATELLITE";
	string s="";
	for(int i=1;i<=300;i++)s=s+"ATELLITE";
	vector<vector<__int128>>dp(s.size()+1,vector<__int128>(9));
	dp[s.size()][8]=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=0;j<8;j++)dp[i][j]=dp[i+1][j]+(s[i]==s0[j+1])*dp[i+1][j+1];
		dp[i][8]=dp[i+1][8];
	}
	for(int i=0;i<s.size();i++)
	{
		while(k&&k>=dp[i][0])k-=dp[i][0],putchar('S');
		putchar(s[i]);
	}
	return 0;
}