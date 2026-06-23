#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const int N=4e5+10;
const int mod=998244353;
ll l[N],r[N];
ll a1[N],b1[N],a2[N],b2[N];


int main()
{
    int n,m;cin>>n>>m;
    ll ans2=0;
    ll mx=0;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        a1[l[i]]++;
        a1[r[i]+1]--;
        mx=max(mx,r[i]+1);

        ll L=n-r[i];
        ll R=n-l[i];
        mx=max(R+1,mx);

        if(L>R){
            swap(L,R);
        }
        a2[L]++;
        a2[R+1]--;

        R=min(r[i],R);
        L=max(L,l[i]);

        ans2+=max((ll)0,R-L+1);

       // cout<<i<<" "<<ans2<<endl;
    }
   // ans2/=2;
    b2[0]=a2[0];

    for(int i=1;i<=mx;i++)
    {
        b1[i]=b1[i-1]+a1[i];
        b2[i]=b2[i-1]+a2[i];
    }

    // for(int i=0;i<=mx;i++)cout<<b1[i]<<" ";cout<<endl;
 //    for(int i=0;i<=mx;i++)cout<<b2[i]<<" ";cout<<endl;

    ll ans=0;

    

    for(int i=0;i<=mx;i++)
    {
        if(i>n)break;
        ans+=b1[i]*b1[n-i];
        //cout<<i<<ans<<endl;
        ans%=mod;
    }
   // cout<<ans<<endl;

    ans-=ans2;
    ans=(ans+mod)%mod;

    cout<<ans<<endl;

}