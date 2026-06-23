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
constexpr i64 P = 998244353;

void solve()
{
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    vector<int> mi(2 * n);
    mi[2 * n - 1] = 1e9;
    for (int i = 2 * n - 2; i >= 0; i--) {
        mi[i] = mi[i + 1];
        if (a[i] != -1) mi[i] = min(a[i], mi[i]);
    }

    i64 ans = 1;
    vector<int> cnt(n + 1);
    int sum = 0, idx = 0;
    auto qpow = [&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            b >>= 1;
            a = a * a % P;
        }
        return res;
    };
    for (int i = 0; i < 2 * n; i++) {
        if (a[i] != -1) {
            sum++;
            cnt[a[i]]++;
        } else {
            while (cnt[idx] == 0) idx++;
            if (idx > mi[i]) {
                ans = 0;
                break;
            }
            ans = ans * cnt[idx] % P * qpow(sum, P - 2) % P;
            cnt[idx]--, sum--;
        }
    }

    cout << ans << "\n";



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