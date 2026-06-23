#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

using i64 = long long;

void solve()
{
    int n, p; cin >> n >> p;
    vector<i64> v(n + 1), sum(n + 2);
    for (int i = 1; i <= n; i++) cin >> v[i], sum[i] = v[i] + sum[i - 1];
    int k, t; cin >> k >> t;
    i64 ans = 0;
    auto calc = [&]() {
        for (int i = 1; i <= p; i++) {
            int l = i, r = min(n, l + t - (p - i) - 1);
            if (r < l) continue;
            int len = r - l + 1;
            i64 val = sum[r] - sum[l - 1] + 1ll * (t + t - len + 1) * len / 2 * k;
            if (r < p) {
                l = r + 1, r = p;
                len = r - l + 1;
                val += (1 + 1 + len - 1) * len / 2 * k;
            }
            ans = max(val, ans);
        }
    };
    calc();
    reverse(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + v[i];
    p = n - p + 1;
    calc();
    cout << ans << '\n';






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