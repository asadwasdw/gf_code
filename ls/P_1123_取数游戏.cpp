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

int a[N][N];
bool st[N][N];
int n, m;
int ans = 0;
void dfs(int x, int y, int sum) {
    if(y == m + 1) {
        x ++;
        y = 1;
    }
    if(x == n + 1) {
        ans = max(ans, sum);
        // cout << sum << endl;
        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= m; j ++) {
        //         cout << st[i][j] << " \n"[j == m];
        //     }
        // }

        return;
    }

    bool ky = true;

    for(int i = -1; i <= 1; i ++) {
        for(int j = -1; j <= 1; j ++) {
            if(st[x + i][y + j]) ky = false;
        }
    }
    
    if(ky) {
        st[x][y] = true;
        dfs(x, y + 1, sum + a[x][y]);
        st[x][y] = false;
    }

    dfs(x, y + 1, sum);

}


void solve()
{
    ans = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    dfs(1, 1, 0);

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
    return 0;
}