#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N=2e5+10;
int a[N];
void solve()
{

    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n;
        int k=a[i]+2;
        while(l<r)
        {
           int mid=l+r+1>>1;
        if(a[mid]<=k)l=mid;
        else r=mid-1;   
        }

        ans+=(long long)(l-i)*(l-i-1)/2;
    }

    cout<<ans<<endl;

}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}