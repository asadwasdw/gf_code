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

int dp[N];
int w[N];
int v[N];
void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;

    int n;cin>>n;
    int m = 0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

            v[i]=max(0ll,(a+b+1)/2-a);
        
        w[i]=c;
        m+=c;
    }
    //cout<<m<<endl;
    int ans = INFll;

    for(int j=1;j<=n;j++)
    {
        for(int i=m;i>=1;i--){
            if(i>=w[j])dp[i]=min(dp[i],dp[i-w[j]]+v[j]);
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(i>m/2)ans=min(ans,dp[i]);
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