#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
// #define int long long
#define LL int
#define PII pair<LL, LL>
using namespace std;

const LL N = 2e5 + 10, M = 1e5;

LL n, m, tt = 0;
LL l[N], r[N];
PII a[N];
int b[N];
int tr[N];
LL lowbit(LL x) { return x & -x; }

void add(LL x, LL d)
{
    while (x <= tt)
    {
        tr[x] = d;
        LL len = lowbit(x);
        for (LL i = 1; i < len; i += lowbit(x))
            tr[x] = max(tr[x], tr[x - i]);
        x += lowbit(x);
    }
}

LL ask(LL l, LL r)
{
    LL mx = 0;
    while (l <= r)
    {
        mx = max(mx, a[r].second);
        r--;
        for (; r - lowbit(r) >= l; r -= lowbit(r))
            mx = max(mx, tr[r]);
    }
    return mx;
}

LL find(LL i, LL j, LL k)
{
    while (i < j)
    {
        LL mid = (i + j) / 2;
        if (k > r[mid])
            i = mid + 1;
        else if (k < l[mid])
            j = mid;
        else
            return mid;
    }
    return tt;
}
void init()
{
    for(int i = 1; i <= tt; i ++) a[i].first = 0, a[i].second = 0, tr[i] = 0;
    tt = 0;
}

void solve()
{
    LL x, y;
    while (cin >> n)
    {
        if(n == 0) break;
        init();
        cin >> m;
        cin >> a[++tt].first;
        a[tt].first += M;
        a[tt].second = 1;
        l[tt] = 1;
        b[1] = a[tt].first;
        queue<PII> q;
        for (LL i = 2; i <= n; i++)
        {
            cin >> x;
            x += M;
            b[i] = x;
         
            if (a[tt].first != x)
            {
                PII t; t.first = tt, t.second = a[tt].second;
                q.push(t);
                r[tt] = i - 1;
                tt++;
                l[tt] = i;
                a[tt].first = x;
                a[tt].second = 1;
            }
            else
                a[tt].second++;
        }
         PII t; t.first = tt, t.second = a[tt].second;
                q.push(t);
        r[tt] = n;

        // build(1, 1, tt);

        while(q.size()) {
            PII t = q.front(); q.pop();
            // modify(1,t.first,t.second);
            add(t.first,t.second);
        }

    

        for (LL i = 0; i < m; i++)
        {
            cin >> x >> y;
            LL L = find(1, tt, x);
            LL R = find(1, tt, y);
            if (R == L) {
                cout << y - x + 1 << '\n';
            } else if (R - L + 1 == 2) {
                cout << max(r[L] - x + 1, y - l[R] + 1) << '\n';
            } else {
                LL t = max(r[L] - x + 1, y - l[R] + 1);
                t = max(t, ask(L + 1, R - 1));
                cout << t << '\n';
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    LL T = 1;
    // cin>>T;
    for (LL i = 1; i <= T; i++)
    {
        // init();
        solve();
    }
}
