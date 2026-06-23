#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
using i64 = long long;
typedef pair<int,int> PII;
unordered_map<ll,bool> st;
unordered_map<int,bool> num;

void dfs(int a, int b) {
    if(a > b) swap(a, b);
    if(st[a * INF + b] == true) return;
    st[a * INF + b] = true;

    num[a] = true;
    num[b] = true;

    dfs(a, a|b);
    dfs(a, a&b);
    dfs(a, a^b);
    dfs(a|b, b);
    dfs(a&b, b);
    dfs(a^b, b);
}

int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(i != 1) {
            dfs(a[i], a[i - 1]);
        }
    }

    cout << num.size() << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}