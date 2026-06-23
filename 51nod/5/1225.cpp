#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=1e9+7;
const int inv=5e8+4;

int main()
{

    ll n;cin>>n;

    ll ans=(n%N)*(n%N)%N;

    ll res=0;// 求1-n  i*(n/i)
    //

    for(ll l=1,r;l<=n;l=r+1)
    {  
        res%=N;
        r=(n/(n/l));
        r=min(r,n);
        res=res+((((n/l)%N)*((l+r)%N))%N*(((r-l)+1)%N)%N*inv)%N;

        //res+=n/l(权)*(l+r)*(r-l+1)/2(等差数列)
        if(res<0){
           cout<<l<<" "<<r<<" ";
          cout<<res<<endl;
        }
        res=(res%N+N)%N;
    }

    ans-=res%N;
    ans=(ans+N)%N;

    cout<<ans<<endl;

}