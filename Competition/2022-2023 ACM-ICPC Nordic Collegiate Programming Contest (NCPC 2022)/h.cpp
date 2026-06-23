#include<iostream>
#include<algorithm>

using namespace std;
const int N = 2e5+10;
typedef long long ll;
ll a[N];

int main()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    a[0]=a[n+1]=0x3f3f3f3f3f3f3f3f;

    int i=1,j=1;
    ll ans=0;
    for(;j<=n&&i<=n;i++)
    {
        while(a[j+1]>=a[j]&&j<=n)j++;

        int t =j;

        while(a[j+1]<=a[j]&&j<=n)j++;

        ans=max(ans,min(a[t]-a[i],a[t]-a[j]));


        i=j-1;
    }

    cout<<ans<<endl;


}