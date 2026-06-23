#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=3e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;



int dp[N][2];

void solve()
{

    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    s=" "+s;

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0'){
            dp[i][1]+=dp[i-1][1]+dp[i-1][0];
            dp[i][0]=1;
        }
        else {
            dp[i][1]+=dp[i-1][0]+1;
            dp[i][0]+=dp[i-1][1];
        }
        ans+=dp[i][1];
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