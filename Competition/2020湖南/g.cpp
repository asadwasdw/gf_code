#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e6+10, mod = 1e9+7;



void solve(){

    int n, m;
    while (cin >> n >> m) {
        vector a(n, vector<int> (m));
        vector<int> sum(n);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];    
        }
        if (n > 2) {
            cout << "No\n";
        } else if (n == 1) {
            cout << "Yes\n";
        } else {
            if ((sum[0] + sum[1]) % 2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}