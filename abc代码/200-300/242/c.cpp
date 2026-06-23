#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e6+10;

typedef long long ll;
const int MOD= 998244353;

ll f[N][15];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=9;i++)f[1][i]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=9;j++)
        {
            f[i][j]+=f[i-1][j];
            if(j!=1)f[i][j]+=f[i-1][j-1];
            if(j!=9)f[i][j]+=f[i-1][j+1];
            f[i][j]%=MOD;
        }
    }

    ll ans=0;

    for(int i=0;i<=9;i++)
    {
        ans+=f[n][i];
      ans%=MOD;
    }

    cout<<ans<<endl;
}
