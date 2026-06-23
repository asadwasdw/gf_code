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
ll s[N][N];

void solve()
{
    int n, m, c;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            // cout << a[i][j] << " \n"[j == m];
        }
    }

   

    int mx = 0, x, y;

    for(int x1 = 1; x1 <= n; x1 ++) {
        for(int y1 = 1; y1 <= m; y1 ++) {

            for(int c = 1; c <= max(n, m); c ++) {
                int x2 = x1 + c - 1;
                int y2 = y1 + c - 1;
                if(x2 > n || y2 > m) continue;

                ll res = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
                if(res == c * c) {
                    // cout << x1 << " " << y1 << " " << " " << res << " " << c << endl;
                    mx = max(c, mx);
                } 

            }
            // cout << x1 << " " << y1 << " " << res << endl;
        }
    }
   cout << mx << endl;








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