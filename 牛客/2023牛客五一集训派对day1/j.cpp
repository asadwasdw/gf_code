#include<iostream>
#include<algorithm>

using namespace std;
const int MOD = 998244353;
typedef long long ll;
#define int long long 

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


int ans[1000010];

signed main()
{
    ans[1]=1*qmi(6,MOD-2,MOD);
    for(int i=2;i<=1000010;i++)
    {
        ans[i]=ans[i-1]*i%MOD*qmi(4*i+2,MOD-2,MOD)%MOD;
    }

    int n;
    while(cin>>n)
    {
        cout<<ans[n]<<endl;
    }


    
}


