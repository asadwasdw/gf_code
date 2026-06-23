#include<algorithm>
#include<iostream>

using namespace std;
const int N=2e5+10;
long long  a[N];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
   // for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    int l=1,r=n;
    long long ans=0;
    while(k--)
    {
       // cout<<a[r]*a[r-1]<<" "<<a[l]*a[l+1]<<" "<<k<<endl;
        if(a[r]*a[r-1]>=a[l]*a[l+1])
        {
           
            ans+=a[r]*a[r-1];
             r-=2;
        }
        else {
          
            ans+=a[l]*a[l+1];
              l+=2;
        }
        
    }
    cout<<ans<<endl;
}