#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


int n,m;
int a[N],b[N];
int dp[N][2];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=n;i;i--){
        b[i]=m/a[i];
        m%=a[i];
    }

    dp[1][0]=1;
    if(b[1])dp[1][1]=1;

    for(int i=1;i<n;i++){
        dp[i+1][0]+=dp[i][0];
        if(b[i+1])dp[i+1][1]+=dp[i][0];
        dp[i+1][1]+=dp[i][1];
        if((b[i+1]+1)!=(a[i+2]/a[i+1]))dp[i+1][0]+=dp[i][1];
        //cout<<b[i+1]+1<<" "<<(a[i+2]/a[i+1])<<endl;
    }
    cout<<dp[n][0]<<endl;

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