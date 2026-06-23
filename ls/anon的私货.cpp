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

int a[N],w[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]=a[i]-1;
    }
    a[0]=a[n+1]=INF;
    int ans = 0;
    for(int i=1;i<=n+1;i++) {
        int t = min(a[i],a[i-1]);
        ans+=t;
        a[i]-=t;
        a[i-1]-=t;
    }
    // for(int i=0;i<=n+1;i++)cout<<a[i]<<" ";cout<<endl;
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