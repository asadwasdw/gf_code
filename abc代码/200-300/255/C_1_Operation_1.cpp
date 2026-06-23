#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    ll x, a, d, n;
    cin>>x>>a>>d>>n;
    if(d<0){
        x=-x,a=-a,d=-d;
    }

    ll ans;

    if(x <= a)ans=a-x;
    else if(x >= a+(n-1)*d)ans = x - (a+(n-1)*d);
    else {
        ans = (x - a)%d;
        ans = min(ans,d-ans); 
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