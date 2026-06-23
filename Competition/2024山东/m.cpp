#include<bits/stdc++.h>
#define int long long
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 1000 + 10, mod = 1e9+7;
const int INFll = 0x3f3f3f3f3f3f3f3f;

struct Point {
    int x, y;
    Point(){}
    Point(int _x, int _y) : x(_x), y(_y) {};
    Point operator+(Point P) const {return {x + P.x, y + P.y};}
    Point operator-(Point P) const {return {x - P.x, y - P.y};}
}p[N];

int a[N];

int det(Point a, Point b) {
    return abs(a.x * b.y - a.y * b.x);
}

int js(int a, int b, int c, int d) {
    int res = det(p[c] - p[a], p[b] - p[a]) + det(p[c] - p[a], p[d] - p[a]);
    return res;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for(int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        p[i] = p[i + n] = {x, y};
    }


    vector  R(2 * n + 1, vector (2 * n + 1, 0));
    vector  L(2 * n + 1, vector (2 * n + 1, 0));
    vector dp(2 * n + 1, vector (2 * n + 1, -INFll));


    for(int i = 1; i <= 2 * n; i ++) {
        dp[i][i] = 0;
        if(i != 2 * n && a[i] == a[i + 1]) {
            dp[i][i + 1] = 0;
        }
    }
    for(int i = 1; i <= 2 * n ; i ++) {
        for(int j = i, t = i ; j <= 2 * n; j ++) {
            L[i][j] = t;
            if(a[i] == a[j]) t = j;
        }
    }

    for(int i = 1; i <= 2 * n ; i ++) {
        for(int j = i, t = i ; j >= 1; j --) {
            R[i][j] = t;
            if(a[i] == a[j]) t = j;
        }
    }

    int ans = 0;
    for(int len = 3; len <= n; len ++) {
        for(int l = 1, r = l + len - 1; r <= 2 * n; r ++, l ++) {
            if(a[l] != a[r]) continue;

            for(int kl = l + 1; kl < r; kl ++) {
                int kr = L[kl][r];
                dp[l][r] = max(dp[l][r], dp[kl][kr] + js(l, kl, kr, r));
            }

            for(int kr = l + 1; kr < r; kr ++) {
                int kl = R[kr][l];
                dp[l][r] = max(dp[l][r], dp[kl][kr] + js(l, kl, kr, r));
            }
        }
    }

    for(int i = 1; i <= 2 * n; i ++) {
        for(int j = 1; j <= 2 * n; j ++) {
            ans = max(dp[i][j], ans);
            // cout << dp[i][j] << " \n"[j == 2 * n];
        }
    }

    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}