#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int M=1e9+7;
ll inv=5e8+4;
ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    a%=p;
    while(b)
    {
        if(b&1)res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}

int main()
{
    ll n;
    cin>>n;
    cout<<qmi(2,M-2,M)<<endl;
    cout<<(ll)(qmi(3,n+1,M)-1+M)%M*inv%M<<endl;
}