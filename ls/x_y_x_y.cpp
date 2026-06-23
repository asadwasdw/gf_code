#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    ull n, m;
    cin >> n >> m;

    ull ans = 0;
    for(ull len = 1, y = 1; y <= n; y *= 10, len ++) {
        ull t = y * 10 - 1;
        ull sumx = (n / (m / __gcd(t, m))) % mod;
        ull sumy = (min(t, n) - y + 1) % mod;
        
        // cout << t << " " << len << " " << y << " " << sumx << " " << sumy << endl;
        ans += sumx * sumy % mod;
        ans %= mod;
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
    return 0;
}