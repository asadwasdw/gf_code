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
int a[N];

int qmi(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    
    int n,x;
    cin>>n>>x;
    dp[0]=1;
    int P = qmi(n,mod-2);
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=n;j++){

            if(a[j]>i)continue;
            dp[i] += dp[i-a[j]]*P%mod;
            dp[i] %= mod;
        }

       // cout<<dp[i]<<endl;
    }


    int ans = 0;
    for(int i=0;i<=x;i++)
    {
        if(i+a[1]>x)ans+=dp[i];
        ans%=mod;
    }
    ans = ans%mod * P%mod;
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