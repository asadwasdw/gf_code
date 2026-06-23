#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


ll qmi(ll a,ll b,ll c)
{
   if (b < 0) return 1;
    ll res =1;
    while(b)
    {
        if(b&1)res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res%c;
}


void solve()
{
    ll n,d;
    cin>>n>>d;
    ll ans=0;

    for(int l=0;l<=d;l++)
    {
        int r = d-l;
        if(max(l,r)>=n)continue;
        ans+= qmi(2,l-1,mod)*qmi(2,r-1,mod)%mod*(qmi(2,n-max(l,r),mod)-1+mod)%mod;
        ans%=mod;
    }

    cout<<ans%mod<<endl;



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