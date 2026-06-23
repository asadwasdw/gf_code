#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;



ll extend_gcd(ll a,ll b,ll&x,ll &y)
{
    if(b==0){x=1,y=0;return a;}

    ll d =extend_gcd(b,a%b,y,x);
     y -= a/b * x ; 
    return d;
}

void solve()
{
    int n,p,x,q,y;
    cin>>n>>p>>x>>q>>y;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        sum+=x;
    }

    int ans= 0x3f3f3f3f3f3f3f3f;

    for(int t2 = 0;t2<=n;t2++)
    {
        int a = x;
        int b = n;

        int X;
        int Y;
        int c  = t2*y-sum;

        ll d =extend_gcd(a,b,X,Y);
        if(c%d!=0)continue;

        int t =(X*(c/d)%(b/d)+(b/d))%(b/d);

        ans = min(t*p+q*t2,ans);

    }
    if(ans==0x3f3f3f3f3f3f3f3f)cout<<"-1"<<endl;
    else cout<<ans<<endl;

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