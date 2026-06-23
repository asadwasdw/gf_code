#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll num = b - a +1;

    ll ans1 = (b/c)-(a-1)/c;
    ll ans2 = (b/d)-(a-1)/d;

    ll t = (c*d)/__gcd(c,d);
    ll ans3 = (b/t)-(a-1)/t;

    //cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

    cout<<num-(ans1+ans2-ans3)<<endl;


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