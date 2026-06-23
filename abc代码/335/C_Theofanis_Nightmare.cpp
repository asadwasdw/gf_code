#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

ll a[N];
ll dp[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    dp[n]=a[n];
    ll s = a[n];
    for(int i=n-1;i;i--){
        dp[i] = max(dp[i+1]+a[i],dp[i+1]+a[i]+s);
        s+=a[i];
    }
    cout <<dp[1]<<endl;
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