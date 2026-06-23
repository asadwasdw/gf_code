#include <bits/stdc++.h>
using namespace std;
struct node {
    int v, w;
} N[110];

struct cmp {
    bool operator ()(int& a, int& b) {
        if (N[a].w == N[b].w)
            return N[a].v > N[b].v;
        return N[a].w > N[b].w;
    }
};

int main() {
    int t, n, m, x, c, ans;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        ans = 0;
        priority_queue<int, vector<int>, cmp >q;
        for (int i = 1; i <= n; i++) {
            cin >> N[i].v;
            N[i].w = 0;
            q.push(i);
        }
        int u = 0, temp;
        while (m--) {
            if (N[q.top()].w >= x)
                break;
            temp = q.top();
            q.pop();
            N[temp].w += N[temp].v;
            q.push(temp);
            u++;
        }
        while (!q.empty()) {
            temp = q.top();
            q.pop();
            if (N[temp].w - x > 0 && N[temp].w - x < N[temp].v)
                ans++;
        }
        cout << u - ans << ' ' << ans << endl;
    }
    return 0;
}