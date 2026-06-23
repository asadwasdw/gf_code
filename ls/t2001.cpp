#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N][N];
int sx, sy, tx, ty;

// dfs判断最短路

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n;
bool vis[N][N]; // vis[x][y] == true; 从sx,sy 到x,y 的时候， 用过了哪些点
typedef pair<int,int> PII;
int ans = 1e9;
vector<PII> l, ansl;

void dfs(int x, int y, int len) { // 当前所在点的坐标，跑到当前点，所花费的步数, 树上点的信息
    // cerr << x << " " << y << " " << len << endl;
    if(x == tx && y == ty) {
        if(ans > len) {
            ansl = l;
            ans = len;
        }
        return;
    }
    
    for(int k = 0; k < 4; k ++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if(a[x][y]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = true;
        l.push_back({nx, ny});
        dfs(nx, ny, len + 1);
        l.pop_back();
        vis[nx][ny] = false;// 如果这个信息和当前搜索的路径有关的时候 
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
    dfs(sx, sy, 1);
    cout << "(" << sx << "," << sy <<")";
    for(int i = 0; i < ansl.size(); i ++) {
        cout << "->(" << ansl[i].first << "," << ansl[i].second << ")";
    }

    return 0;
}