#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef pair<int,int> PII;
const int N = 1e6 + 10, M = N;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m;

int check(vector<vector<char>> &a) {
    if(a[0][0] == 'B') return -1;
    if(a[n - 1][m - 1] == 'B') return -1;
    queue<PII> q;
    q.push({0, 0});
    vector<vector<bool>> st(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, -1));
    dis[0][0] = 1;

    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if(st[tx][ty]) continue;
            if(a[tx][ty] == 'B') continue;
            st[tx][ty] = true;
            dis[tx][ty] = dis[x][y] + 1;
            q.push({tx, ty});
        }
    }
    return dis[n - 1][m - 1];
}


void solve() {
    
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    int res = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'W') res ++;
        }
    }

    int t = check(a);
    if(t == -1 || (res - t) % 2 == 0 ) {
        cout << "J\n";
    } else {
        cout << "I\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}





// int sg(vector<vector<char>> a) {
//     if(!check(a))return 0;
//     set<int> s;

//     for(int i = 0; i < n; i ++) {
//         for(int j = 0; j < m; j ++) {

//             if(i == 0 && j == 0) continue;
//             if(i == n - 1 && j == m - 1) continue;

//             if(a[i][j] == 'W') {
//                 a[i][j] = 'B';
//                 s.insert(sg(a));
//                 a[i][j] = 'W';
//             }
//         }
//     }

//     // for(int i = 0; i < n; i ++) {
//     //     for(int j = 0; j < m; j ++) {
//     //         cerr << a[i][j] << " \n"[j == m - 1];
//     //     }
//     // }
//     int res = 0;
//     while(s.count(res)) res ++;
//     // cerr << res << endl;
//     return res;
// }
