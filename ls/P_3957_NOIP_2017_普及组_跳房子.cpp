// https://www.luogu.com.cn/problem/P3957
#include <bits/stdc++.h>
using namespace std;
long long n, d, k;
long long f[500005];
deque<long long> q;
struct Gird {
    long long x, s;
} g[500005];
bool check(long long money) {
    memset(f, -127, sizeof f);
    long long j = 0;
    long long minjump = max(d - money, 1ll);
    long long maxjump = d + money;
    f[0] = 0;
    for (long long i = 1; i <= n; i ++) {
        while (g[i].x - g[j].x >= minjump && j < i) {
            if (f[j] >= -9999999) {
                while (!q.empty() && f[q.back()] <= f[j])
                    q.pop_back();
                q.push_back(j);
            }
            j ++;
        }
        while (!q.empty() && g[i].x - g[q.front()].x > maxjump)
            q.pop_front();
        if (!q.empty())
            f[i] = f[q.front()] + g[i].s;
        
        // cout << i << " " << f[i] << " " << q.size() << endl;
        if (f[i] >= k)
            return true;
    }
    return false;
}
int main() {
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i ++)
        cin >> g[i].x >> g[i].s;

        // cout << check(2) << endl;
    int l, r;
    l = 0; // 蓝色区域(ok)
    r = 1e9; // 红色区域
    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(mid))
            l = mid + 1; // 拓展蓝色区域
        else
            r = mid; // 拓展红色区域
    }
    if(l >= 1e9) l = -1;
    cout << l << endl;
    return 0;
}