#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


ll bh(ll x,ll k)
{
    ll res = 0;
    ll t=1;
    while(x)
    {
        res+=(x%10)*t;
        t*=k;
        x/=10;
    }
    return res;

}


void solve()
{
    ll a,b,k;
    cin>>k>>a>>b;

    a=bh(a,k);
    b=bh(b,k);

    cout<<a*b<<endl;







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