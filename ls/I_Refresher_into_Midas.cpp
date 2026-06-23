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

using i64 = long long;
// i64 a, b, m;
void solve()
{
    i64 a, b, m;cin >> a >> b >> m;
    i64 ans;
    if (a > b) {
        ans =(m / b) + 2;
    } else {
        i64 t = (b + a - 1) / a * a;
        ans = (t / a + 1) * (m / t) + (m % t + a) / a + (m % t + b) / b;
        i64 ans2 = (m / b) * ((b + a - 1) / a) + 2 + (m % b) / a;
        ans = max(ans, ans2);
        // cerr << a << ' ' << b << ' ' << m << '\n';
        // cerr << ans << ' ' << ans2 << "\n";
        // assert(ans >= ans2);
    }
    cout << ans * 160 << "\n";





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
        // for (int x = 10; x <= 100; x++)
        // for (int y = x; y <= 100; y++)
        // for (int j = 1; j <= 100; j++) {
        //     a = x, b = y, m = j;
            solve();
        // }
    }
}