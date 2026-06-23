#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;



int a[N];
int dp[N][15];
void solve()
{

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[1][a[1]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=10;j++)
        {
            dp[i+1][(j+a[i+1])%10]+=dp[i][j];
            dp[i+1][(j*a[i+1])%10]+=dp[i][j];
            dp[i+1][(j+a[i+1])%10]%=mod;
            dp[i+1][(j*a[i+1])%10]%=mod;
        }
    }

    for(int i=0;i<=9;i++)cout<<dp[n][i]<<endl;


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