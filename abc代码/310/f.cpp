#include<bits/stdc++.h>
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
    return res;
}


void solve()
{

    int n;
    cin>>n;

    vector<ll>dp(1ll<<10);
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        ll m=min(10ll,x);
        ll inv = qmi(x,mod-2);
        vector<ll>g(1ll<<10);
        for(ll s=0;s<(1ll<<10);s++)
        {
            for(int j=1;j<=m;j++)
            {
                g[(s|(s<<j)|((1<<(j-1))))&((1ll<<10)-1)]+=dp[s]*inv%mod;
                g[(s|(s<<j)|((1<<(j-1))))&((1ll<<10)-1)]%=mod;
            }
            g[s] += dp [s]*(x-m)%mod*inv%mod;
            g[s]%=mod;
        }
        swap(dp,g);
    }

    ll ans =0;
    for(int i=(1<<9);i<(1<<10);i++)
    {
        ans+=dp[i];
        ans%=mod;
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