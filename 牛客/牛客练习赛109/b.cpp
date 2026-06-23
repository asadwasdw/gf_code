#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;
const int N=1e6+10;
int a[N];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i+j<=n;j++)
        {
            int t=pow(-1,j-1);

            //cout<<i<<" "<<j<<" "<<t<<" "<<a[i+j]<<" "<<a[i]+t*(j+1)/2<<endl;
            if(a[i+j]!=a[i]+t*(j+1)/2){
                ans=max(j,ans);
                break;
            } 

            if(i+j==n&&a[i+j]==a[i]+t*(j+1)/2)ans=max(j+1,ans);
        }
    }
    cout<<ans<<endl;
}