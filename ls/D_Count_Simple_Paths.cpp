#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
int n, m;
int ans = 0;
char a[15][15];
bool vis[15][15];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y, int k) {
    if(k == 0) {
        ans ++;
        return;
    }

    for(int i = 0; i < 4; i ++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(a[tx][ty] == '#') continue;
        if(vis[tx][ty]) continue;
        vis[tx][ty] = true;
        dfs(tx, ty, k - 1);
        vis[tx][ty] = false;
    }
}

void solve()
{
    int k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] == '#') continue;
            vis[i][j] = true;
            dfs(i, j, k);
            vis[i][j] = false;
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
}