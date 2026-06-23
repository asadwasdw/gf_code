#include<iostream>
#include<algorithm>

using namespace std;

const int  mod =998244353;

typedef long long ll;

ll qmi(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res;
}

int main()
{
    ll m,n;
    cin>>m>>n;
    cout<<(qmi(n-1,m,mod)%mod+qmi(-1,m,mod)*(n-1)%mod+mod)%mod;

}