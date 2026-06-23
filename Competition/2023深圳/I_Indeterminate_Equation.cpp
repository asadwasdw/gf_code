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

using i128 = __int128;
using i64 = long long;
void solve()
{

    i64 n, k; cin >> n >> k;
    vector C(k + 1, vector<i128> (k + 1));
    C[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int ans = 0;
    i128 limit;
    {
        i128 l = 1, r = 1e10;
        auto check1 = [&](i128 x) -> bool {
            i128 tmp = 1;
            for (int i = 1; i < k; i++) {
                tmp = tmp * x;
                if (tmp > 1e18) return true;
            }
            return false;
        };
        while (l < r) {
            i128 m = (l + r) >> 1;
            if (check1(m)) r = m;
            else l = m + 1;
        }
        limit = l;
    }
    for (i128 t = 1;; t++) {

        vector<i128> v(k);
        bool ok = true;
        i128 tmp = t;
        i128 sum = 0;
        for (int i = k - 1; i >= 0; i--) {
            v[i] = C[k][i] * tmp;
            sum += v[i];
            if (sum > n) ok = false;
            tmp = tmp * t;
        }
        if (!ok) break;
        
        if (k == 3) {
            if ((4 * n - t * t * t) % (3 * t)) continue;
        }
        i128 l = 1, r = limit;
        bool flag = false;
        auto check = [&](i128 x) -> int {
            i128 tmp = 1;
            i128 m = n;
            for (int i = 0; i < k; i++) {
                if (tmp > m) return 2;
                m -= v[i] * tmp;
                tmp = tmp * x;
                if (m < 0) return 2;
            }
            return m == 0;
        };
        while (l <= r) {
            i128 m = (l + r + 1) >> 1;
            int val = check(m);
            
            if (val == 1) {
                flag = true;            
                break;
            }
            if (val < 1) l = m + 1;
            else r = m - 1; 
        }
        if (flag) ans++;
    }

    cout << ans << "\n";
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
}