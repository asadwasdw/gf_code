#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>s(N);

int dp[110][N];
void solve()
{
    memset(dp, -1, sizeof dp);

    int n, kk, q;
    cin >> n >> kk >> q;
    for(int i = 1; i <= n; i ++) {
        s[i].clear();
        int m; cin >> m;
        for(int j = 0; j < m ; j ++) {
            int x; cin >> x;
            s[i].push_back(x);
        }
    }

    dp[0][1] = 0;
    for(int i = 1; i <= 100; i ++) {
        for(int j = 1; j <= n; j ++) {
            int len = 0;
            for(auto k : s[j]) {
                if(len > 0) {
                    if(dp[i][k] == -1) dp[i][k] = j;
                    else if(dp[i][k] != j) dp[i][k] = 0;
                    len --; 
                }
                if(dp[i - 1][k] >= 0 && dp[i - 1][k] != j) len = kk - 1;
            }
        }
    }


    while(q --) {
        int x, y; cin >> x >> y;
        if(dp[x][y] == -1) cout << "0\n";
        else cout << "1\n"; 
    }









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
}