#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
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

    int n,m;
    cin>>n>>m;

    m=n+m;
    ll ans = 1;
   // cout<<m<<endl;

    for(int i=1;i<=35;i++)
    {
        if(n<=(1ll<<i)-1){

            ll tmp = qmi(2,i-1);
            ll len = min((1ll<<i)-1,m)-n;


            tmp = qmi(tmp,mod-2);
            tmp = (1+mod-tmp)%mod;
            tmp = qmi(tmp,len);
            //cout<<tmp<<endl;
            ans *= tmp;
            //cout<<ans<<endl;
            ans%=mod;
            n+=len;
            if(n>=m)break;
        }
    }

    cout<<ans<<endl;

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