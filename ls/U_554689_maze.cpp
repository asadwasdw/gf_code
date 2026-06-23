#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
int n;
int c[N][N];
bool flag = false;
int sx, sy, tx, ty;
// bool vis[N][N];
int dis[N][N];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

// sxzy
map<PII,PII> pre;

void dfs(int x, int y) {
    // cout << x << " " << y << endl;
    if(x == tx && y == ty) {
        return;
    }

    for(int k = 0; k < 4; k ++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(xx < 1 || xx > n || yy < 1 || yy > n) continue; 
        if(c[xx][yy]) continue;
        // cout << dis[xx][yy] << " " << dis[x][y] + 1 << endl;
        if(dis[xx][yy] > dis[x][y] + 1) {
            dis[xx][yy] = dis[x][y] + 1;
            pre[{xx, yy}] = {x, y};
            dfs(xx, yy);
        }
        
    }
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> c[i][j];
        }
    }

    memset(dis, 0x3f, sizeof dis);
    cin >> sx >> sy >> tx >> ty;
    dis[sx][sy] = 1;
    dfs(sx, sy);
    // if(flag) cout << "Yes";
   // else cout << "No";

    // cout << dis[tx][ty] << endl;

    stack<PII> sta;

    // cout << pre[{2, 2}].first << " " << pre[{2, 2}].second << endl;

    while(!(tx == sx && ty == sy)) {
        sta.push({tx, ty});
        PII pre_node = pre[{tx, ty}];
        tx = pre_node.first;
        ty = pre_node.second;
    }

    cout << "(" << sx << "," << sy<<")";

    while(sta.size()) {
        cout << "->(" << sta.top().first << "," << sta.top().second<<")";
        sta.pop();
    }






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