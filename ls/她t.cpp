#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N][N];
int sx, sy, tx, ty;

// dfs判断联通性

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
bool vis[N][N]; // vis[x][y] == true; 从sx,sy 可以到达的点
bool ans = false;

void dfs(int x, int y) { // 当前所在点的坐标， 树上点的信息
    // cerr << x << " " << y << endl;
    if(x == tx && y == ty) {
        ans = true;
        return;
    }

    for(int k = 0; k < 4; k ++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if(a[nx][ny]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx, ny);
    }

}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    cin >> sx >> sy >> tx >> ty;
    vis[sx][sy] = true;
    dfs(sx, sy);

    if(ans) cout << "Yes";
    else cout << "No";

    return 0;
}