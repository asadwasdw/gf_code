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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) {
        b[i]=a[i]+b[i-1];
    }
    int l = 1,r=1;

    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans+=(n-l)*2*a[i];
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