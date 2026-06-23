#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10, mod = 1e9+7;

using i64 = long long;
constexpr i64 P = 998244353;


int a[100][100];

void solve(){
    cout << "Yes\n";
    int n;
    cin >> n;

    
    for(int j = 3; j <= n; j ++) {
        a[1][j] = a[2][j] = j + 2;
    }

    for(int i = 3; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++) {
            a[i][j] = n + i;
        }
    }

    a[1][1] = 1;
    a[1][2] = 2;
    a[2][1] = 3;
    a[2][2] = 4;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << a[i][j] << " \n"[j == n];
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