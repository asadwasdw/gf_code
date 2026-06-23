#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

struct D
{
    int num;
    vector<string>s;
}d[200];

int dp[200];


void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    string s;
    cin>>s;
    int len = s.size();
    s=" "+s;
    int n;
    cin>>n;
    // cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cin>>d[i].num;
        for(int j=1;j<=d[i].num;j++){
            string t;
            cin>>t;
            d[i].s.push_back(t);
        }
    }
    
    for(int j=1;j<=n;j++) {
        for(int i = len - 1;i >= 0 ;i--) {
            // if(dp[i]==INF)continue;
            for(auto t:d[j].s) {
                // cout << s.substr(i + 1,t.size())<<" "<<t<<endl;
                if(s.substr(i + 1,t.size()) == t) {
                    dp[i + t.size()] = min(dp[i] + 1,dp[i + t.size()]);
                }
            }
        }
    }
    

    if(dp[len] >= INF)dp[len] = -1;
    cout<<dp[len]<<'\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}