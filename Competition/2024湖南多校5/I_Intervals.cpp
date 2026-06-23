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


void solve()
{

    int n;cin >> n;
    vector<int> a(n), mp(n), l(n, 0), r(n, n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 1; i < n; i++) {
        if (mp[i] > mp[i - 1]) {
            r[mp[i - 1]] = mp[i] - 1;
        }else {
            l[mp[i - 1]] = mp[i] + 1;
        }
    }

    cout << 1ll * mp[0] * (mp[0] + 1) / 2 + 1ll * (n - mp[0] - 1) * (n - mp[0]) / 2 << ' ';

    int L = mp[0], R = mp[0];
    // int lv = 0, rv = 0;
    for (int i = 1; i < n; i++) {
        if (mp[i] >= L && mp[i] <= R) {
            cout << 0 << ' ';
        }else {
            ll lv = L, rv = n - 1 - R;
            if (mp[i] > R) rv = mp[i] - 1 - R;
            if (mp[i] < L) lv = L - mp[i] - 1;
            // cout << lv << ' ' << rv << ' ';
            cout << (lv + 1) * (rv + 1) << ' ';
            // cout << 1ll * (L - l[L] + 1) * (r[R] - R + 1) << ' ';
        }
        if (mp[i] > R) {
            R = mp[i];
        }
        if (mp[i] < L) {
            L = mp[i];
        }
    }
    cout << "1\n";




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