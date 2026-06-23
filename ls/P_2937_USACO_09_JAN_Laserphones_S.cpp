#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=10007;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int fa[N][20];
int deep[N];

void dfs(int u, int father) {
    deep[u] = deep[father] + 1;
    fa[u][0] = father;
    for(int i = 1; (1 << i) < deep[u]; i ++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for(auto v : adj[u]) {
        if(v == father) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i --) {
        if(deep[x] - (1 << i) >= deep[y]) {
            x = fa[x][i];
        }
    }
    if(x == y) return x;

    for(int i = 19; i >= 0; i --) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int len(int x, int y) {
    return deep[x] + deep[y] - 2 * deep[lca(x, y)];
}

int d[110][110];
char c[110][110];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void solve()
{
    int n, m;
    cin >> m >> n;
    memset(d, 0x3f, sizeof d);

    int sx = 0, sy = 0, tx = 0, ty = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> c[i][j];
            if(c[i][j] == 'C') {
                if(!sx) {
                    sx = i, sy = j;
                } else {
                    tx = i, ty = j;
                }
            }
        }
    }


    queue<PII> que1, que2;
    que1.push({sx, sy});
    d[sx][sy] = 0;


    for(int i = 1; i <= n * m; i ++) {
        if(que1.size() == 0) break;

        while(que1.size()) {
            auto [x, y] = que1.front(); que1.pop();
            for(int k = 0; k < 4; k ++) {
                for(int j = 1; j <= max(n, m); j ++) {
                    int tx = x + dx[k] * j;
                    int ty = y + dy[k] * j;
                    if(tx < 1 || tx > n || ty < 1 || ty > m) break;
                    if(c[tx][ty] == '*') break;
                    if(d[tx][ty] < d[x][y] + 1) break;
                    d[tx][ty] = d[x][y] + 1;
                    que2.push({tx, ty});
                }
            }
        }

        swap(que1, que2);
        
    }
    cout << d[tx][ty] - 1 << endl;
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