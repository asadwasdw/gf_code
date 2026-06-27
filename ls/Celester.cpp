#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int x[N], y[N];

int dp[N][3][3]; // 0晴天 1阴天，

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int j = 1; j < n; j ++) cin >> y[j];

    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int z = 0; z < 2; z++) dp[i][j][z] = -INF;
        }
    }
    map<char,int> id;
    id['S'] = 0;
    id['R'] = 1;
    for(int t = 0; t < 4; t ++) {
        int w = 0;
        int s1 = id[s[1]], s2 = id[s[2]];
        if(t & 1) w -= x[1], s1 ^= 1;
        if(t & 2) w -= x[2], s2 ^= 1;

        dp[2][s1][s2] = w;
        if(s1 == 1 && s2 == 0) dp[2][s1][s2] += y[1];
    }


    for(int i = 3; i <= n; i ++) {
        for(int s1 = 0; s1 < 2; s1 ++) {
            for(int s2 = 0; s2 < 2; s2 ++) {
                for(int op = 0; op < 2; op ++) {
                    int s3 = id[s[i]];
                    int w = 0;
                    if(op) s3 ^= 1, w -= x[i];
                    if(s2 == 1 && s3 == 0) w += y[i - 1];

                    dp[i][s2][s3] = max(dp[i][s2][s3], dp[i - 1][s1][s2] + w);
                }
            }
        }
    }
    int ans = -INF;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int z = 0; z < 2; z ++) {
                ans = max(ans, dp[i][j][z]);
                // cout << i << " " << j << " " << z << " " << dp[i][j][z] << endl;
                
            }
        }
    }
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}