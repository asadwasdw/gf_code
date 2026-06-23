#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;
typedef long long ll;
const int N=50010,MOD=1e9+7;
int n;
int f[321][N];



signed main()
{
    cin>>n;
    f[0][0]=1;

    for(int i=1;i<=320;i++)
    {
        for(int j=i;j<=n;j++)
        {
            f[i][j]=((ll)f[i][j-i]+f[i-1][j-i])%MOD;
        }
    }
    ll ans=0;
    for(int i=1;i<=320;i++)
    {
        ans+=f[i][n];
    }

    cout<<ans%MOD<<endl;
}
