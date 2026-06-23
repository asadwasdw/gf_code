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

//vector<vector<int>>adj(N);

set<PII> s;
int n, m, k;
char c[N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


void dfs(int x, int y, int d, int k) {
    s.insert({x, y});
    if(k == 0) return;

    int tx = dx[d] + x;
    int ty = dy[d] + y;

    if(1 <= tx && tx <= n && 1 <= ty && ty <= m && c[tx][ty] == '.') {
        dfs(tx, ty, d, k - 1);
    } else {
        dfs(x, y, (d + 1) % 4, k - 1);
    }
}

void solve()
{
    s.clear();

    cin >> n >> m >> k;
    int x, y, d;
    cin >> x >> y >> d;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> c[i][j];
        }
    }

    dfs(x, y, d, k);

    cout << s.size() << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}