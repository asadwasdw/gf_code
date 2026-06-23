#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int n;

void solve()
{
    cin>>n;

   vector<vector<int>>dp(n+10,vector<int>(3,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1];
        if(i%2&&a[i]>0){
            dp[i][1]+=a[i];
        }
    }

    for(int i=n;i>=1;i--){
        dp[i][2]=dp[i+1][2];
        if(a[i]>=0){
            dp[i][2]+=a[i];
        }
    }

    int ans = 0;

    for(int i=2;i<=n;i+=2){
        ans =max(dp[i-1][1]+dp[i+1][2],ans);
    }
    for(int i=1;i<=n;i+=2){
        ans =max(dp[i-1][1]+dp[i+1][2]+a[i],ans);
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