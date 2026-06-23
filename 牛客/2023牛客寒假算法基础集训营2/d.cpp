#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const int N=4e6+10;
const int mod=998244353;
ll l[N],r[N];
ll a1[N],b1[N],a2[N],b2[N];


int main()
{
    int n,m;cin>>n>>m;
    ll ans2=0;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        a1[l[i]]++;
        a1[r[i]+1]--;


        ll L=n-r[i];
        ll R=n-l[i];

        if(L>R){
            swap(L,R);
        }
        R=min(r[i],R);
        L=max(L,l[i]);
        ans2+=max((ll)0,R-L+1);

    }


    for(int i=1;i<=n;i++)
    {
        b1[i]=b1[i-1]+a1[i];
    }


    ll ans=0;
      ans-=ans2;

    for(int i=1;i<=n;i++)
    {
          ans+=b1[i]*b1[n-i];
        ans%=mod;
    }
   // cout<<ans<<endl;
 
  
    ans=(ans+mod)%mod;
   cout<<ans<<endl;

}