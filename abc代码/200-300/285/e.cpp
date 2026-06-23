#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=5000+10;
ll a[N];
ll b[N];

const ll INF =0x3f3f3f3f3f3f3f3f;
ll f[N][N];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[(i+1)/2];

  memset(f,0x8f8f,sizeof f);

   f[1][0]=0;


    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            f[i+1][j+1]=f[i][j];
            f[i+1][0]=max(f[i+1][0],f[i][j]+b[j]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[n][i]+b[i]);
    }


    cout<<ans<<endl;

}
