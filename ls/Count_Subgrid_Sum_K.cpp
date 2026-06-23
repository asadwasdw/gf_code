#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

const int N = 510;
int a[N][N], s[N][N];

int get(int x1, int y1, int x2, int y2) {
    if(y2 < y1) return 0;
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            char c; cin >> c;
            if(c == '1') a[i][j] = 1;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

        }
    }

    ll ans = 0;
    for(int u = 1; u <= n; u ++) {
        for(int d = u; d <= n; d ++) {
            int res1 = 0, res2 = 0;
            for(int l1 = 1, l2 = 1, r = 1; r <= m; r ++) {
                res1 += get(u, r, d, r);
                res2 += get(u, r, d, r);

                while(l1 <= r && res1 > k) {
                    res1 -= get(u, l1, d, l1);
                    l1 ++;
                }
                while(l2 <= r && res2 >= k)  {
                    res2 -= get(u, l2, d, l2);
                    l2 ++;
                }
                
                ans += l2 - l1;
                
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