#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=500+10, M = N * N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define x first
#define y second
vector<PII> st[M];
int a[N][N];
int dp[N][N];
int x[N],y[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n;i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            // char t;cin >> t; a[i][j] = t - '0';
            st[a[i][j]].push_back({i,j});
            if(a[i][j] == 1) {
                dp[i][j] = 0;
            }
        }
    }
    
    int ans = -1;
    if(k == 1) {
        ans = 0;
    }

    for(int i = 2; i <= k; i ++) {
        memset(x,0x3f,sizeof x);
        memset(y,0x3f,sizeof y);
        for(auto [X,Y] : st[i - 1]) {
            x[X] = min(x[X],dp[X][Y]);
            y[Y] = min(y[Y],dp[X][Y]);
        }

        for(auto [X,Y] : st[i]) {
            for(int i = 1; i <= n; i ++) {
                dp[X][Y] = min({dp[X][Y], x[i] + (i-X)*(i-X)});
                dp[X][Y] = min({dp[X][Y], y[i] + (i-Y)*(i-Y)});
            }
            if(i == k && dp[X][Y] != INFll) {
                if(ans != -1) ans = min(ans, dp[X][Y]);
                else ans = dp[X][Y];
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
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}