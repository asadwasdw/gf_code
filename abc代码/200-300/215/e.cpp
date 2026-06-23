#include<iostream>
#include<algorithm>
const int N=1050;

using namespace std;
int dp[N][N][15];
char s[N];

int main()
{
    int n;
    cin>>n>>(s+1);
    long long num;
    for(int i=1;i<=n;i++)
    {
        num=s[i]-'A';
        dp[i][1<<num][num]+=1;
        for(int j=0;j<1024;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(!dp[i-1][j][k])continue;
                if(j&(1<<num)==0)dp[i][j][num]+=dp[i-1][j]

            }

        }
    }

}