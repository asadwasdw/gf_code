#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int h[N], d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    stack<int> s;
    for (int j = 1; j <= n; j++) {
        while (!s.empty() && h[s.top()] < h[j]) {
            int mid = s.top();
            s.pop();
            if (!s.empty()) {
                int i = s.top();
                // 航线 (i, j) 成立，跨越区间 [i+1, j-1]
                if (j - i > 1) {
                    d[i + 1]++;
                    d[j]--;
                }
            }
        }
        s.push(j);
    }

    int ans = 0;
    int current = 0;
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        ans = max(ans, d[i]);
    }

    cout << ans << endl;

    return 0;
}