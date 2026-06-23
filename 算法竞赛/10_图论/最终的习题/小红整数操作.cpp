#include<bits/stdc++.h>
#define int long long
#define double long double
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
    double x,y,l,r;
    cin>>x>>y>>l>>r;

    if(x<y){
        r=r*(x/y);
    }
    else {
        l=l*(x/y);
    }
    x=x/__gcd((int)x,(int)y);

    // cout<<l<<" "<<r<<endl;
    int ans1 = (l-1)/x;
    int ans2 = (r)/x;

    // cout<<ans2<<" "<<ans1<<endl;
    cout<<ans2-ans1<<endl;







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