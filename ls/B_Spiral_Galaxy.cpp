#include<bits/stdc++.h>
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

const int N=1e1+10;
char a[N][N];


bool check(int u, int d, int l, int r) {

    for(int i = u; i <= d; i ++) {
        for(int j = l; j <= r; j ++) {
            if(a[i][j] != a[u + d - i][l + r - j]) return false;
        }
    }

    return true;
}

void solve()
{

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        } 
    }

    int ans = 0;

    for(int u = 1; u <= n; u ++) {
        for(int d = u; d <= n; d ++) {
            for(int l = 1; l <= m; l ++) {
                for(int r = l; r <= m; r ++) {
                    if(check(u, d, l, r)) {
                        ans ++;
                    }
                }
            }
        }
    }
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
    return 0;
}