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


void solve()
{
    ll n, m, x;
    cin >> n >> m >> x;

    vector a(n + 1, vector(m + 1, 0ll));
    ll res = 0;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ll sum = 0;
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            a[i][j] = max(a[i - 1][j], a[i][j]);
            sum += a[i][j];
        }
        res = max(res, sum);
        if(x >= res) ans = max(i, ans);
        // cout << i << " " << sum << " " << res << " " << x << endl;
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