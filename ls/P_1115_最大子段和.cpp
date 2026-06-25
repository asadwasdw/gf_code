#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
int a[N], b[N], s[N];
int n;

const int INF = 0x3f3f3f3f;

int dp[N];
int main() {

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = -INF;
    for(int i = 1; i <= n; i ++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}