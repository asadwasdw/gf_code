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
    vector<vector<int>> t(100);
    for (int i = 0; i < n; i++) {
        int s;cin >> s;
        t[s % 100].emplace_back(s % 10000);
    }
    sort(t.begin(), t.end(), [&](vector<int> &x, vector<int> &y) {
        return x.size() > y.size();
    });
    vector<int> cnt(100);
    for (int i = 0; i < 100; i++) {

        sort(t[i].begin(), t[i].end());
        for (int l = 0, r = -1; l < t[i].size(); l = r + 1) {
            while (r + 1 < t[i].size() && t[i][r + 1] % 10000 == t[i][l] % 10000) r++;
            cnt[i] = max(cnt[i], r - l + 1);
        }
    }
    ll ans = 0;
    for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++) {
        if (j == i) continue;
        ll res = cnt[i] * 4000 + (!t[j].empty()) * 300000;
        int tmp = 0;
        for (int k = 0; k < 100 && tmp < 3; k++) {
            if (i == k || j == k) continue;
            res += 500 * t[k].size(); tmp++;
        } 
        ans = max(ans, res);
    }
    cout << ans << '\n';
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