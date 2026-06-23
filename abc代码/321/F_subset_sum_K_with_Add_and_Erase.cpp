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

multiset<int>s;

vector<int>dp(5010);

void solve()
{
    int n,k;
    cin>>n>>k;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        char t;
        int x;
        cin>>t>>x;
        if(t=='+'){
            vector<int>dp2(5010);
            dp2=dp;
            for(int i=x;i<=k;i++){
                dp2[i]=(dp[i]+dp[i-x])%mod;
            }
            dp=dp2;
        }
        else {
            vector<int>dp2(5010);
            for(int i=x;i<=k;i++){
                dp[i]=(dp[i]-dp[i-x]+mod)%mod;
            }
        }
        //for(int i=0;i<=k;i++)cout<<dp[i]<<" ";cout<<endl;
        cout<<dp[k]<<endl;
    }
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