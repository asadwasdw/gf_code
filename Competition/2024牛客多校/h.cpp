#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10, M = 4e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


unordered_map<int,vector<int>> edg;
int n,m;
char a[N][N];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int ans[M];
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



set<PII> s;
bool st[N][N][4];
 

void dfs(int x, int y, int d) {
    if(st[x][y][d]) return;
    st[x][y][d] = true;
   
    auto [tx, ty, td] = xx(x, y, d);

    if(tx == -1) return;

    if(d != td)s.insert({tx,ty});
    dfs(tx, ty, td);
}



void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }



    int q;
    cin >> q;
    while(q --) {
        int x, y, d;
        string ss;
        cin >> x >> y; cin >> ss;
        x--, y--;
        if(ss == "right") d = 0;
        if(ss == "below") d = 1;
        if(ss == "left")  d = 2;
        if(ss == "above") d = 3;
        dfs(x, y, d);
        cout << s.size() << endl;

    }




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