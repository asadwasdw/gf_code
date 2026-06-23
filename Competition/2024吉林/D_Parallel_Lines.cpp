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

    int n, k; cin >> n >> k;
    vector<array<i64, 2>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    int root = rand() % n;
    for (int j = 0; j < n; j++) {
        if (j == root) continue;
        i64 dx = a[root][0] - a[j][0];
        i64 dy = a[root][1] - a[j][1];
        map<i64, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i][1] * dx - a[i][0] * dy].emplace_back(i);
        }
        if (mp.size() == k) {
            for (auto [_, v] : mp) {
                cout << v.size() << ' ';
                for (auto x : v) cout << x + 1 << ' ';
                cout << '\n';
            } 
            break;
        }
    }

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}