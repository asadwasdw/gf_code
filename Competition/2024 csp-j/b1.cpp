#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char a[1010][1010];
bool st[1010][1010];
int n, m, k;

void dfs(int x, int y, int d, int k) {
    if(k == -1)return;
    st[x][y] = true;
    int tx = x + dx[d];
    int ty = y + dy[d];
    if(tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] == 'x' ) {
        dfs(x, y, (d+1)%4, k - 1);
    } else {
        dfs(tx, ty, d, k - 1);
    }

}

void solve()
{
    cin >> n >> m >> k;
    int x0,y0,d0; cin >> x0 >> y0 >> d0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            st[i][j] = false;
        }
    }
    dfs(x0, y0, d0, k);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++){
            if(st[i][j]) ans ++;
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
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}