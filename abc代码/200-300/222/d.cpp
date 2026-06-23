#include<iostream>
#include<algorithm>

using namespace std;
#define int long long
const int M=998244353;
const int N=3e3+10;
int a[N];
int b[N];
int f[N][N];
int s[N][N];

signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    
    }

    for(int i=1;i<=n;i++)cin>>b[i];



    for(int i=1;i<=n;i++){
        int t=0;
        int k=a[i-1];
        for(int j=a[i];j<=b[i];j++)
        {
            if(i==1){
                f[i][j]=1;
                continue;
            }

            for(k;k<=j;k++)
            {
                t+=f[i-1][k];
                t%=M;
            }

            f[i][j]=t;
            f[i][j]%=M;

        }
    }



    //   for(int i=1;i<=n;i++)
    //   {

    //       for(int j=1;j<=b[n];j++){
    //         cout<<f[i][j]<<" ";
    //       }
    //       cout<<endl;

    //   }
      

    int ans=0;

    for(int i=0;i<=max(a[n],b[n]);i++)
    {
        ans+=f[n][i];
        ans%=M;
    }
    cout<<ans%M<<endl;




}