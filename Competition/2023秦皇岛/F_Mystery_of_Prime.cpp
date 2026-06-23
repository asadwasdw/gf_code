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
int dp[N][4];
int prime[N],st[N],cnt;

void qie_p()
{
    for(int i=2;i<N;i++)
    {
        if(!st[i])prime[cnt++]=i;
        
        for(int j=0;i*prime[j]<N;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }

    // for(int i=1;i<=100;i++){
    //     if(!st[i])cout<<i<<endl;
    // }
    
}




void solve()
{
    qie_p();
    memset(dp,0x3f,sizeof dp);
    
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    dp[1][0]=0;
    dp[1][1]=dp[1][2]=dp[1][3]=1;
    if(a[1]==1){
        dp[1][1]=0;
    }

    for(int i=2;i<=n;i++)
    {
        {//不变
            if(a[i]==1){
                dp[i][0] = min(dp[i-1][1],dp[i][0]);
                dp[i][0] = min(dp[i-1][2],dp[i][0]);
            }
            else if(a[i]%2==0) {
                dp[i][0] = min(dp[i][0],dp[i-1][3]);
                
            }
            else {
                dp[i][0] = min(dp[i][0],dp[i-1][2]);
            }
            if(!st[a[i]+1])dp[i][0]=min(dp[i][0],dp[i-1][1]);
            if(!st[a[i-1]+a[i]]) dp[i][0] = min(dp[i][0],dp[i-1][0]);
        }

        {//变成1
            if(a[i]==1){
                dp[i][1]=dp[i][0];
            }
            else {
                dp[i][1] = min(dp[i-1][1]+1,dp[i][1]);
                dp[i][1] = min(dp[i-1][2]+1,dp[i][1]);
                if(!st[a[i-1]+1])dp[i][1] = min(dp[i-1][0]+1,dp[i][1]);
            }
        }

        {
            dp[i][2] = min(dp[i][2],dp[i-1][3]+1);
            dp[i][2] = min(dp[i][2],dp[i-1][1]+1);
            if(a[i-1]%2 == 1) {
                dp[i][2]=min(dp[i][2],dp[i-1][0]+1);
            }
        }

        {
            dp[i][3] = min(dp[i][3],dp[i-1][2]+1);
            if(a[i-1]%2==0) {
                dp[i][3]=min(dp[i][3],dp[i-1][0]+1);
            }
        }

    }

    cout<<min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]});
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