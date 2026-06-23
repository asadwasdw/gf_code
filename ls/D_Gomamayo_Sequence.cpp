#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N); 

int dp[N][2][2];
int c[N];

void solve()
{
    int n;
    cin >>n;
    string s;
    cin >> s;
    s=" "  + s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][s[1]-'0'][0] = 0;
    dp[1][(s[1]-'0')^1][0] = c[1];

    for(int i=2;i<=n;i++){
        for(int j=0;j<2;j++){
            int t = s[i]-'0';
            if(t == j) {

                dp[i][t^1][1] = min(dp[i][t^1][1],dp[i-1][j][1] + c[i]);
                dp[i][t^1][0] = min(dp[i][t^1][0],dp[i-1][j][0] + c[i]);

                dp[i][t][1] = min(dp[i][t][1],dp[i-1][j][0]);
            }
            else {
                dp[i][t][1] = min(dp[i][t][1], dp[i-1][j][1]);
                dp[i][t][0] = min(dp[i][t][0], dp[i-1][j][0]);

                dp[i][t^1][1] = min(dp[i][t^1][1], dp[i-1][j][0] + c[i]);
                // dp[i][t^1][0] = min(dp[i][t^1][0], dp[i-1][j][0] + c[i]);
            }
        }
        // cout << min({dp[i][1][1],dp[i][1][0],dp[i][0][1],dp[i][0][0]})<<endl;
    }

    cout << min({dp[n][1][1],dp[n][0][1]});







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}