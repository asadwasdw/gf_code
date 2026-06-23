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

ll xorsum = 0;
ll ans = 0;
ll n, m;
ll a[25][25];
bool b[25][25];

void dfs(int x, int y, ll res) {
    // if(res == 131071) {
    //     for(int i = 1; i <= n; i ++ ) {
    //         for(int j = 1; j <= m; j ++) {
    //             cout << b[i][j] << " \n"[j == m];
    //         }
    //     }
    // }

    ans = max(ans, res);
    if(y > m) {
        y = 1;
        x ++;
    }
    if(x > n) return;
    
    dfs(x, y + 1, res);

    if(b[x][y] == false && y < m && b[x][y + 1] == false) {
        b[x][y] = true;
        b[x][y + 1] = true;

        dfs(x, y + 1, res ^ a[x][y] ^ a[x][y + 1]);

        b[x][y] = false;
        b[x][y + 1] = false;
    }

    if(b[x][y] == false && x < n && b[x + 1][y] == false) {
        b[x][y] = true;
        b[x + 1][y] = true;

        dfs(x, y + 1, res ^ a[x][y] ^ a[x + 1][y]);

        b[x][y] = false;
        b[x + 1][y] = false;
    }
}



void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            xorsum ^= a[i][j];
        }
    }
    
    ans = xorsum;
    // cout << ans << endl;
    dfs(1, 1, xorsum);

    cout << ans;

    

    








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