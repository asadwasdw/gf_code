#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

typedef long long ll;

const int N=2e5+10;

ll a[N],b[N];

int main()
{
    ll n,m,d;
    cin>>n>>m>>d;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int j=1;j<=m;j++)cin>>b[j];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    b[m+1]=0x3f3f3f3f3f3f3f3f;


    ll ans=-1;

    ll mx=1;

    for(int i=1;i<=n;i++)
    {
        while(mx+1<=m&&b[mx+1]<=a[i]+d)
        {
            //cout<<b[mx+1]<<" "<<a[i]+d<<endl;
            mx++;
        }

        if(b[mx]<=a[i]+d&&b[mx]>=a[i]-d)ans=max(a[i]+b[mx],ans);

        //cout<<b[mx]<<endl;
    }


    cout<<ans<<endl;


}