#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


ll dp[N];



void solve()
{

    int n;
    cin>>n;
    cout<<dp[n]%mod<<endl;
}


signed main()
{
    
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=N-1;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2]*2)%mod;
    }

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}