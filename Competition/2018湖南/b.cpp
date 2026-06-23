#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2e6+10, INF = 0x3f3f3f3f, mod = 1e9+7;



void solve() {
    int n,m;
    while(cin >> n >> m){
        if(m >= n)cout << m + 1 << endl;
        else cout << n << endl;    
    }
    
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}