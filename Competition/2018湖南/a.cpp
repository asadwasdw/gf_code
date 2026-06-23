#include<bits/stdc++.h>

#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2000+10, INF = 0x3f3f3f3f, mod = 1e9+7;

int n,m;
ll a[N][N];

void solve() {
    for(int i=1; i<N; ++i)a[1][i] = a[i][1] = i;
    for(int i=2; i<N; ++i)for(int j=2; j<N; ++j){
        a[i][j] = (a[i-1][j] + a[i][j-1] + 1) % mod;
    }
    while(cin >> n >> m){
        cout << a[n][m] * a[n][m] % mod << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}