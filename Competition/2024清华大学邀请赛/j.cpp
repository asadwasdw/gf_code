#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef pair<int,int> PII;
const int N = 1e6 + 10, M = N;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m;

map<vector<vector<int>>, int> SG;
int sg(vector<vector<int>> a) {
    if(SG.count(a)) return SG[a];
    vector<int> row(n), col(m);
    set<int> s;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        if(row[i] == 0) continue;
        vector<int> t(m, 0);
        for(int j = 0; j < m; j ++) {t[j] = a[i][j], a[i][j] = 0;}
        s.insert(sg(a));
        for(int j = 0; j < m; j ++) {a[i][j] = t[j];}
    }


    for(int j = 0; j < n; j ++) {
        if(col[j] == 0) continue;
        vector<int> t(n, 0);
        for(int i = 0; i < n; i ++) {t[i] = a[i][j], a[i][j] = 0;}
        s.insert(sg(a));
        for(int i = 0; i < n; i ++) {a[i][j] = t[i];}
    }

    int res = 0;
    while(s.count(res)) res ++;

    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < m; j ++) {
    //         cout << a[i][j] << " \n"[j == m - 1];
    //     }
    // }
    // cout << res << endl << endl;

    SG[a] = res;
    return res;
}
vector<vector<int>> a;
void dfs(int x, int y, int cnt) {

    if(cnt == 3) {

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << a[i][j] << " \n"[j == m - 1];
            }
        }

        cout << sg(a) << endl << endl;
        return;
    }
    if(y == m) {
        y = 0;
        x ++;
    }
    if(x >= n) {
        return;
    }

    dfs(x, y + 1, cnt);
    a[x][y] = 0;
    dfs(x, y + 1, cnt + 1);
    a[x][y] = 1;
}



void solve() {
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i ++) {
        a[i].resize(m, 1);
    }
    dfs(0, 0, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}





