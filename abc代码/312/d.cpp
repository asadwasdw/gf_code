#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dp[N][N];
string s;


void solve()
{

    cin>>s;
    int n =s.size();
    s=" "+s;
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='('){
            for(int j=1;j<=n;j++)
            {
               dp[i][j]+=dp[i-1][j-1];
               dp[i][j]%=mod;
            }
        }
        else if(s[i]==')'){
            for(int j=0;j<n;j++){
                dp[i][j]+=dp[i-1][j+1];
                 dp[i][j]%=mod;
            }
        }
        else 
        {
            for(int j=0;j<=n;j++)
            {
                 if(j>0)dp[i][j]+=dp[i-1][j-1];
                 dp[i][j]+=dp[i-1][j+1];
                  dp[i][j]%=mod;
            }
        }
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