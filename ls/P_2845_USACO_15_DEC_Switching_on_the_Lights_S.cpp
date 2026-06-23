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
map<PII, vector<PII>> st;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

bool vis[N][N], t[N][N];
int ans = 0;
void dfs(int x, int y) {
    // cout << x << " " << y << endl;
    vis[x][y] = true;
    for(auto [tx, ty] : st[{x, y}]) {
        t[tx][ty] = true;
        bool ky = false;
        for(int i = 0; i < 4; i ++) {
            if(vis[tx][ty]) continue;
            int ttx = tx + dx[i];
            int tty = ty + dy[i];
            if(ttx < 1 || ttx > n || tty < 1 || tty > n) continue;
            if(vis[ttx][tty]) ky = true;
        }
        // cout << tx << " " << ty << " " << ky << endl;
        if(ky)dfs(tx, ty);
    }


    for(int i = 0; i < 4; i ++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
        if(vis[tx][ty]) continue;
        if(!t[tx][ty]) continue;
        
        dfs(tx, ty);
    }
}

void solve()
{
    cin >> n >> m;

    for(int i = 1; i <= m; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        st[{a, b}].push_back({c, d});
    }

    t[1][1] = true;
    dfs(1, 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(t[i][j]) ans ++;
        }
    }
    cout << ans;

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