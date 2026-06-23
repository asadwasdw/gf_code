#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
typedef unsigned long long ull;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int h[N * N];
int a[N][N];
bool vis[N][N];
vector<PII> v;
int ans = 0;
int minx = INF, miny = INF;
int n, m;
void dfs(int x, int y, int c) {
    vis[x][y] = true;
    v.push_back({x, y});
    minx = min(x, minx);
    miny = min(y, miny);

    for(int k = 0; k < 4; k ++) {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(vis[tx][ty]) continue;
        if(a[tx][ty] != c) continue;
        dfs(tx, ty, c);
    }
}

map<ull,int> cnt;
void check(int x, int y) {
    v.clear();
    minx = miny = INF;
    dfs(x, y, a[x][y]);

    sort(v.begin(), v.end(), [&](PII a, PII b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    ull res = 0;
    for(int i = 0; i < v.size(); i ++) {
        auto [x, y] = v[i];
        x -= minx;
        y -= miny;
        res += (x * N + y) * h[i];
    }
    
    cnt[res] ++;

    if(cnt[res] == 1) ans ++;
}


void solve()
{
    cin >> n >> m;

    for(int i = 0; i <= n * m; i ++) {
        h[i] = rand();
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(!vis[i][j]) {
                check(i, j);
            }
        }
    }
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
    return 0;
}