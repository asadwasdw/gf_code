#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int tr[N][2];

void add(int x,int k,int t)
{
    for(int i=x;i<N;i+= i&-i )
    {
        tr[i][t]+=k;
        tr[i][t]%=mod;
    }
}

ll sum(int x,int t)
{
    ll res = 0;
    for(int i=x;i;i-=i&-i)
    {
        res+=tr[i][t];
        res%=mod;
    }
    return res%mod;
}

ll ask(int l,int r,int t)
{
    return (sum(r,t)%mod-sum(l-1,t)%mod+mod)%mod;
}

ll qmi(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res%c;
}


void solve()
{
    int n;cin>>n;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;

        ans += x;
        ans += 2*ask(1,x,1)%mod*x%mod;
        ans += 2*ask(x+1,N,0)%mod;
        ans%=mod;

       // cout<<ask(1,x,1)*x<<endl;

        ll t = qmi(qmi(i,2,mod),mod-2,mod)%mod;
        //cout<<ans<<" "<<t<<endl;
        cout<<ans*t%mod<<endl;

        add(x,1,1);
        add(x,x,0);
    }









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