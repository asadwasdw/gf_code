#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int a[N][N];
int s[N][N];
int n, m, k, l;
int js(int x, int y) {
    return abs(s[x][y] - s[x - k][y] - s[x][y - l] + s[x - k][y - l]);
}

void solve()
{
    
    cin >> n >> m >> k >> l;
    k = n - k + 1;
    l = m - l + 1;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            s[i][j] = -s[i - 1][j - 1] + s[i][j - 1] + s[i - 1][j] + a[i][j];
        }
    }
    int ans = 0;
    for(int i = k; i <= n; i ++) {
        for(int j = l; j <= m; j ++) {
            ans += js(i,j);
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
}