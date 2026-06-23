#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define int long long 

const int N= 5e5+10;

int f[N];

int n,m;

signed main()
{
    cin>>n>>m;

    vector<vector<int>>a(n+10,vector<int>(m+10,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=min(m,n-i+1);j++)
        {
            cin>>a[i][j];
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n+1;j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    memset(f,0x3f,sizeof f);
    f[1]= a[1][0];

    for(int i=2;i<=n+1;i++)
    {
        for(int j=max(1ll,i-m);j<i;j++)
        {
            //cout<<i<<" "<<j<<endl;
            f[i]=min(f[j]-a[j][i-j]+a[i][0],f[i]);
        }
    }

    //for(int i=1;i<=n+1;i++)cout<<i<<" "<<f[i]<<endl;

    cout<<f[n+1]<<endl;


}
