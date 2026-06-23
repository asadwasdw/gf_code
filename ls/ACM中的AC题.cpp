#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

char a[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void solve()
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    vector dis(n + 1, vector (m + 1, INF));
    vector dis2(n + 1, vector (m + 1, INF));

    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    {
        queue<PII> q;
        for(int i = 1; i <= n; i ++ ) {
            for(int j = 1; j <= m; j ++) {
                if(a[i][j] == '@') {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }


        while(q.size()) {
            auto [x, y] = q.front(); q.pop();
            for(int k = 0; k < 4; k ++) {
                int tx = x + dx[k];
                int ty = y + dy[k];
                if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
                if(a[tx][ty] == '#')continue;
                if(dis[tx][ty] == INF) {
                    dis[tx][ty] = dis[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }

        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= m; j ++) {
        //         cout << dis[i][j] << " \n"[j == m];
        //     }
        // }
   }

   queue<PII> q;
   q.push({sx, sy});
   dis2[sx][sy] = 0;

   int ans = INF;

    while(q.size()) {
        auto [x1, y1] = q.front(); q.pop();
        int x2 = 2 * sx - x1, y2 = 2 * sy - y1;
        // cout << x1 << " " << y1 << " "<< x2 << " " << y2 << endl;

        for(int k = 0; k < 4; k ++) {
            int tx1 = x1 + dx[k];
            int ty1 = y1 + dy[k];

            int tx2 = x2 - dx[k];
            int ty2 = y2 - dy[k];

            if(tx1 < 1 || tx1 > n || ty1 < 1 || ty2 > m) continue;
            if(tx2 < 1 || tx2 > n || ty2 < 1 || ty2 > m) continue;
            if(a[tx1][ty1] == '#' || a[tx2][ty2] == '#') continue;
            int d = dis2[x1][y1] + 1;
            if(a[tx1][ty1] == '@') {
                // cout << tx1 << " " << ty1 << " " << d << " " << dis[tx2][ty2] << endl;
                ans = min(ans, d + dis[tx2][ty2]);
            } else if(a[tx2][ty2] == '@') {
                ans = min(ans, d + dis[tx1][ty1]);
            } else if(dis2[tx1][ty1] == INF) {
                dis2[tx1][ty1] = d;
                q.push({tx1, ty1});
            }
        }
    }

    if(ans >= INF/2) ans = -1;
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