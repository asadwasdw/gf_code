#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


ll dp[N];
ll ans[N];

ll qmi(ll a,ll b)
{
    ll res =1;
    while(b){
        if(b&1)res =res *a%mod;
        b>>=1;
        a=a*a%mod;
    }

    return res ;
}

void solve()
{
    int n , p ;
    cin>>n>>p;

    ll P = p*qmi(100,mod-2)%mod;
    ll P2 = (100-p)*qmi(100,mod-2)%mod;
   // cout<<P<<" "<<P2<<endl;
    //dp[n]=1;

    // for(int i=n;i;i--)
    // {
    //     dp[i]+=1;
    //     int t  = i-1;
    //     dp[t] += dp[i]*P2%mod;
    //    // ans[t]+=dp[i];

    //     t--;
    //     t=max(0,t);

    //     dp[t] += dp[i]*P%mod;
    //   //  ans[t]+=dp[i];
    // }

    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" "<<i<<endl;
    //     dp[i]=0;
    // }

    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i] = ((dp[i-2]*(P)%mod+dp[i-1]*(P2)%mod)+1)%mod;
    }

    cout<<dp[n]<<endl;



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