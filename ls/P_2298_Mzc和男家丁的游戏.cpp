#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


const int N=2e3+10;
char c[N][N];
int dis[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve()
{
    int n, m;
    cin >> n >> m;
    int sx, sy;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> c[i][j];
            if(c[i][j] == 'm') sx = i, sy = j;
        }
    }

    queue<PII> q;
    memset(dis, 0x3f, sizeof dis);
    dis[sx][sy] = 0;
    q.push({sx, sy});
    while(q.size()) {
        int x = q.front().first, y = q.front().second; q.pop();
        if(c[x][y] == 'd') {
            cout << dis[x][y] << endl;
            return;
        }

        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(c[tx][ty] == '#') continue;
            if(dis[tx][ty] <= dis[x][y] + 1) continue;
            dis[tx][ty] = dis[x][y] + 1;
            q.push({tx, ty});
        }
    } 


    cout << "No Way!";
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
    return 0;
}