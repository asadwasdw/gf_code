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

//vector<vector<int>>adj(N);
int dx[] = {-1,0,1};
int dy[] = {0,1,0};
int n, m, ans = -INFll;
int a[1100][1100];
bool st[1100][1100];

void dfs(int x, int y, int sum) {
    if(x == n && y == m) {
        ans = max(sum, ans);
        return;
    }

    for(int k = 0; k < 3; k ++) {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if(tx < 1 || tx > n ||ty < 1 || ty > m) continue;
        if(st[tx][ty]) continue;
        st[tx][ty] = true;
        dfs(tx, ty, sum + a[tx][ty]);
        st[tx][ty] = false;
    }
}

int s[1100][1100], dp[1100][1100];

int get(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    memset(dp, -0x3f, sizeof dp);
    for(int i = 1; i <= n; i ++) {
        dp[i][1] = s[i][1];
    }


    // for(int j = 2; j <= m; j ++) {
    //     for(int i = 1; i <= n; i ++) {
    //         for(int k = 1; k <= n; k ++) {
    //             dp[i][j] = max(dp[i][j], dp[k][j - 1] + get(min(i, k),j, max(i, k),j));
    //         }
    //     }
    // }

    for(int j = 2; j <= m; j ++) {
        {
            priority_queue<PII> q;
            int sum = 0;
            for(int i = 1; i <= n; i ++) {
                q.push({dp[i][j - 1] - sum, i});
                sum += a[i][j];
                int k = q.top().second;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + get(k,j,i,j));
            }
        }

        {
            priority_queue<PII> q;
            int sum = 0;
            for(int i = n; i >= 1; i --) {
                q.push({dp[i][j - 1] - sum, i});
                sum += a[i][j];
                int k = q.top().second;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + get(i,j,k,j));
            }
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++) {
    //         cout << dp[i][j] << " \n"[j == m];
    //     }
    // }
    cout << dp[n][m] << endl;









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