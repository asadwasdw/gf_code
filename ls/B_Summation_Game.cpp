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
int s[N];
void solve()
{
    int n;cin>>n;
    int k,x;
    cin>>k>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    int r=n;
    int ans=-INF;
    for(int i=0;i<=k;i++){
        int t1 = s[max(0ll,r-x)] - (s[max(0ll,r)] - s[max(0ll,r-x)]);
        r--;
        ans=max(ans,t1);
        // cout<<t1<<endl;
    }
    cout<<ans<<endl;

    

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