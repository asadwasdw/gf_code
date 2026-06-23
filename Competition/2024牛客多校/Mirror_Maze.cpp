#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10, M = 4e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


unordered_map<int,vector<PII>> edg;
int n,m;
char a[N][N];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
// 右 下 左 上

bool ish[N][N][4];

array<int,3> xx(int x, int y, int d) {
    int tx, ty, td;
    tx = x + dx[d];
    ty = y + dy[d];
    td = d;

    if(tx < 0 || ty < 0 || tx >= n || ty >= m) return {-1,-1,-1};
    
    if(d % 2 == 1) { // 上下方向
        if(a[tx][ty] == '-') td ^= 2; //转180
        if(a[tx][ty] == '\\') (td += 3);// 逆时针90
        if(a[tx][ty] == '/') (td += 1); // 顺时针90
    } 
    else {
        if(a[tx][ty] == '|') td ^= 2; //转180
        if(a[tx][ty] == '/') (td += 3);// 逆时针90
        if(a[tx][ty] == '\\') (td += 1); // 顺时针90
    }
    td %= 4;

    return {tx, ty, td};
}

int id(int x, int y, int d) {
    return ((x * m + y) << 2 ) ^ d;
}

PII fid(int t) {
    t >>= 2;
    return {t / m, t % m};
}

int bd[N]; // 度

void add(int x, int y, int d) {
    auto [tx, ty, td] = xx(x, y, d);
    

    if(tx == -1) return;
    printf("{%d,%d,%d -> %d,%d,%d}\n", x, y, d, tx, ty, td);
    int u = id(x, y, d), v = id(tx, ty, td);
    cout << u << " " << v << endl;
    edg[u].push_back({v, (td != d)});
    bd[v] ++;
}

int cnt[N][N];
int ans[M];
int res = 0;
bool js;

void add(int t) {
    auto [x, y] = fid(t);
    if(cnt[x][y] ++ == 0) res++;
}

void cul(int t) {
    auto [x, y] = fid(t);
    if(--cnt[x][y]  == 0) res--;
}


void jsh(int U) {
    stack<int> s;
    int u = U;
    vector<int> jl;
    while(1) {
        
    }
}


void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int k = 0; k < 4; k ++) {
               add(i, j, k);
                // cout << id(i, j, k) << " \n"[k == 3];
            }
        }
    }
    int T = n * m * 4;

    queue<int> q;
    for(int i = 0; i < T; i ++) {
        if(bd[i] == 0) q.push(i);
    }

    
    for(int i = 0; i < T; i ++) {
        cout << bd[i] << " \n"[i == T - 1];
    }
    

    while (q.size()) {
        int u = q.front(); q.pop();
        for(auto [v, _] : edg[u]) {
            bd[v] --;
            if(bd[v] == 0) q.push(v);
        }
    }

   
    for(int i = 0; i < T; i ++) {
        // cout << bd[i] << " \n"[i == T - 1];
    //    jsh(i);
    }






    // int q;
    // cin >> q;
    // while(q --) {
    //     int x, y, d;
    //     string s;
    //     cin >> x >> y; cin >> s;
    //     x--, y--;
    //     if(s == "right") d = 0;
    //     if(s == "below") d = 1;
    //     if(s == "left")  d = 2;
    //     if(s == "above") d = 3;
    //     cout << ans[x][y][d] << endl;
    // }





    // cout << "s" << endl;
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
}