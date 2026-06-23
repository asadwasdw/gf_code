#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

using i64 = long long;
void solve()
{
    int n, m; cin >> n >> m;
    i64 k; cin >> k;
    vector<array<i64, 3>> ask(m);
    for (int i = 0; i < m; i++)
    for (int j = 0; j < 3; j++)
        cin >> ask[i][j];
    sort(ask.begin(), ask.end());

    auto check = [&](i64 t) -> bool {
        int idx;
        vector<i64> cnt(n + 1);
        for (int i = 0; i < m; i++) {
            if (ask[i][0] > t) {
                idx = i;
                break;
            }
            cnt[ask[i][1]] = 0;
        }
        i64 now = t;
        for (int i = idx - 1; i >= 0; i--) {
            i64 tmp = (ask[i][2] + k - 1) / k;
            i64 lent = (t - ask[i][0]); 
            i64 ned;
            if (tmp > lent) {
                ned = 0;
            } else {
                ned = lent - tmp + 1;
            }
            cout << ned << ' ';
            // if (tmp < 0) return false;
            ned = max(0ll, ned - cnt[ask[i][1]]);
            cnt[ask[i][1]] += ned;
            now -= ned; 
            cout << now << '\n';
            if (now < ask[i][0]) return false;
        }
        return true;
    };
    i64 l = 0, r = 1e18;
    // while (l < r) {
    //     i64 m = (l + r + 1) >> 1;
    //     if (check(m))l = m;
    //     else r = m - 1; 
    // }
    cout << check(6) << ' ';
    cout << check(7) << ' ';
    cout << l << '\n';





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