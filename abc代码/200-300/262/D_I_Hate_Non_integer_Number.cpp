#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=110+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int num[N];
int a[N];


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans = 0;

    for(int num=2;num<=n;num++){
        vector<vector<int>> dp(N,vector<int>(N,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=num-1;j>=0;j--){
                for(int k=0;k<num;k++){
                    dp[j+1][(k+a[i])%num]+=dp[j][k];
                    dp[j+1][(k+a[i])%num]%=mod;
                }
            }
        }
       // cout<<num<<" "<<dp[num][0]<<endl;

        // for(int i=0;i<=num;i++)
        // {
        //     for(int j=0;j<num;j++)cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }cout<<endl;
        ans+=dp[num][0];
        ans%=mod;
    }

    cout<<ans+n<<endl;


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