#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll qmi(ll a,ll b)
{
    ll res =1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res%mod;
}


void solve()
{

    ll n;cin>>n;
    n%=mod;

    cout<<n%mod*(n+1)%mod*(n+2)%mod*qmi(2,mod-2)%mod*qmi(3,mod-2)%mod<<endl;




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}