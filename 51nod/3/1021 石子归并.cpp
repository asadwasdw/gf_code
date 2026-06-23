#include<iostream>
#include<algorithm>

using namespace std;

const int N=110;
int f[N][N];
int a[N];


int main()
{
    int n;cin>>n;

    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=0x3f3f3f3f;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
       // cout<<a[i]<<endl;
       f[i][i]=0;
    }

    for(int len=2;len<=n;len++)
    {
        for(int l=1,r;l+len-1<=n;l++)
        {
            r=l+len-1;
            for(int k=l;k<r;k++)
            {
               // cout<<l<<k<<r<<endl;
                f[l][r]=min(f[l][k]+f[k+1][r]+a[r]-a[l-1],f[l][r]);
            }
        }
    }

    cout<<f[1][n]<<endl;

}