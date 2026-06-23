#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;


void solve()
{
    ll a,b;
    cin>>a>>b;

    if(a%b!=0){
        cout<<a<<endl;
        return;
    }
    
    ll mx=0;
    for(ll i=2;i*i<=b;i++)
    {
        if(b%i!=0)continue;

        ll t=0;
        while(b%i==0)
        {
            t++;
            b/=i;
        }
        ll T=a;

        while(T%i==0)T/=i;

        for(int j=1;j<t;j++)T*=i;

        mx=max(mx,T);
    }
    //cout<<a<<" "<<b<<endl;
    if(b!=1)
    {
        ll T=a;
        while(T%b==0)T/=b;
        mx=max(mx,T);
    }
  

    cout<<mx<<endl;

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}