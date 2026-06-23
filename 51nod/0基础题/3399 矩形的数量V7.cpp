#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


typedef long long ll;
const ll MOD = 1000000007;

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

void solve()
{

    ll n,m,x,y,x2,y2;
    cin>>n>>m>>x>>y>>x2>>y2;

    ll ny=qmi(2,MOD-2,MOD);

   // cout<<n*(n+1)/2*m*(m+1)/2<<endl;

    ll sum =(n)*(n+1)%MOD*ny%MOD*m%MOD*(m+1)%MOD*ny%MOD;

    ll yd1 = x*(n-x+1)%MOD*y%MOD*(m-y+1)%MOD;

    ll yd2 = x2*(n-x2+1)%MOD*y2%MOD*(m-y2+1)%MOD;

    ll minx=min(x,x2);
    ll maxx=max(x,x2);
    ll miny=min(y,y2);
    ll maxy=max(y,y2);
    
    ll ch = minx*(n-maxx+1)%MOD*miny%MOD*(m-maxy+1)%MOD;

    // cout<<sum<<endl;

    //cout<<ch<<endl;

    ll ans=(sum-yd1-yd2+ch+5*MOD)%MOD;

    cout<<ans<<endl;
    


}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}