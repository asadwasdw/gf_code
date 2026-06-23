#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int a[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    sort(a+1,a+2*n+1);
    int ans = a[n]-a[1] + a[2*n]-a[n+1];
    cout<<ans<<"\n";
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" " <<a[i+n]<<"\n";
    }



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