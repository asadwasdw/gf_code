#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int N=5010;

typedef long long ll;
ll a[N],c[N],d[N][N];


int main()
{
    ll n,p;cin>>n>>p;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            c[a[i]*a[j]%p]++;
            d[i][a[i]*a[j]%p]+=2;
        }
    }

    for(int x=0;x<=p-1;x++){
        ll ans=0;
        for(int k=1;k<=n;k++)
        {
            ll t=((x-a[k])%p+p)%p;
            ans+=c[t]-d[k][t];
        }
        cout<<ans<<" ";
    }


}
