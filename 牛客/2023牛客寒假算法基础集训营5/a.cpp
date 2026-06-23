#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int N=2e5+10;
long long a[N];
long long f[N];
int main()
{
    long long n;cin>>n;
      int q;
      cin>>q;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
    }
    f[n+1]=f[n];
    

    while(q--)
    {
        int k,x;cin>>k>>x;
       // cout<<m[x]<<" ";
       int l=0,r=n;
       while(l<r)
       {
         int mid=(l+r+1)>>1;
         if(a[mid]<=x)l=mid;
         else r=mid-1;
       }
       //cout<<l<<endl;
        cout<<f[l]-f[max(0,l-k)]<<endl;
            
    }
  

    
}