#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char a[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
int cnt, u, d, l, r;

void dfs(int x, int y) {
    cnt ++;
    a[x][y] = '.';

    u = min(u, x);
    d = max(d, x);
    l = min(l, y);
    r = max(r, y);

    for(int k = 0; k < 4; k ++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if(a[nx][ny] == '.') continue;
        dfs(nx, ny);
    }
}


int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] == '.') continue; 
            u = l = 1e9, d = r = -1e9, cnt = 0;
            dfs(i, j);

            if((r - l + 1) * (d - u + 1) == cnt) ans ++;
            else {
                // cout << i << " " << j << " " << u << " " << d << " " << l << " " << r << " " << cnt << endl;  
                cout << "Bad placement.";
                return 0;
            }

        }
    }

    cout << "There are " << ans << " ships.";

    return 0;
}