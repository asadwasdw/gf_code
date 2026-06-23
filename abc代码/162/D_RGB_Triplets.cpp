#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

ll dp[N][100];
int js(char t)
{
    if(t=='R')return 1;
    if(t=='B')return 2;
    if(t=='G')return 4;
}

void solve()
{

    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int t= js(s[i]);
        for(int j=0;j<8;j++)
        {
            dp[i][j]+=dp[i-1][j];
            if(!dp[i-1][j])continue;
            if(t&j)continue;
            //cout<<t<<" "<<j<<" "<<(j|t)<<" "<<dp[i-1][j]<<endl;
            dp[i][(j|t)]+=dp[i-1][j];
            //cout<<i<<" "<<(j|t)<<" "<<dp[i][(j|t)]<<endl;
        }

       // for(int j=0;j<8;j++)cout<<dp[i][j]<<" ";cout<<endl;
    }
    //cout<<dp[1][1]<<endl;
    //cout<<dp[n][7]<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int k = 2*j-i;

            if(k>n)continue;

            if(s[i]!=s[j]&&s[i]!=s[k]&&s[j]!=s[k])dp[n][7]--;
        }
    }
    cout<<dp[n][7]<<endl;







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