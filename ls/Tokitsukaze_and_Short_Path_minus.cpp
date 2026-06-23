#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];
int b[N];

void solve()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);

    ll ans = a[1]*(n-1)*2;
    // cout<<ans<<endl;
    for(ll i=2;i<=n;i++) {
        ll w = min(a[i]*2,a[1]*4);
        ans+=(n-i)*w;
        // cout<<ans<<" "<<w<<endl;
     
    }



    cout<<ans*2<<endl;






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}