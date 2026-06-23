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
constexpr i64 P = 1e9 + 7;
void solve()
{
    i64 n, m; cin >> n >> m;
    vector<array<i64, 2>> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i][0] >> a[i][1];
    
    bool ok = false;
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == n && a[i][1] == m) {
            ok = true;
        }
    }
    if (ok) {
        i64 ans = 1;
        for (int i = 0; i < 3; i++) {
            ans = ans * (n - a[i][0] + 1) % P * (m - a[i][1] + 1) % P;
        }
        cout << ans << "\n";
        return;
    }
    auto calc = [&]() -> i64 {
        vector<array<i64, 2>> b, c;
        for (int i = 0; i < 3; i++) {
            if (a[i][0] == n) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        i64 ans = 0;
        if (b.size() == 0) ans = 0;
        else if (b.size() == 1) {
            if (c[0][0] + c[1][0] < n || min(c[0][1], c[1][1]) + b[0][1] < m) ans = 0;
            else {
                if (min(c[0][1], c[1][1]) == m) {
                    ans = 2 * (m - b[0][1] + 1) % P;
                } else {
                    ans = 4;
                }
            }
        } else if (b.size() == 2) {
            if (b[0][1] + b[1][1] < m) ans = 0;
            else {
                ans = 2 * (n - c[0][0] + 1) % P * (m - c[0][1] + 1) % P;
            }
        } else {
            i64 sum = b[0][1] + b[1][1] + b[2][1];
            if (sum < m) ans = 0;
            else {
                for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    int k = 1 ^ 2 ^ i ^ j;
                    if (b[i][1] + b[j][1] >= m) {
                        ans = (ans + m - b[k][1] - 1) % P;
                        
                    } else {
                        i64 l = max(1ll, m - b[j][1] - b[k][1]);
                        i64 r = min(m - 1 - b[k][1], b[i][1]);
                        i64 val = (r - l + 1) % P;
                        ans = (ans + val) % P;
                    }
                }
                for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    int k = 1 ^ 2 ^ i ^ j;
                    if (max(b[i][1], b[k][1]) + b[j][1] >= m) ans = (ans + 1) % P;
                }
            }
        }
        return ans;
    };
    i64 ans = 0;
    ans = max(ans, calc());
    swap(n, m);
    for (int i = 0; i < 3; i++) swap(a[i][0], a[i][1]);
    ans = max(ans, calc());
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