// #pragma GCC optimize("Ofast", "inline", "-ffast-math")
// #pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
// #define int long long
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const int N = 1e6 + 50, LOGN = 30;
const ll mod = 1e9 + 7, inf = 1e9;
constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

struct Node {
    int cnt;
    vector<array<int, 2>> v;

    Node(int x = 0) {
        cnt = 1;
        for (auto p : primes) {
            if (p * p > x) break;
            if (x % p) continue;
            int t = 0;
            while (x % p == 0) t++, x /= p;
            v.push_back({p, t});
        }
        if (x > 1) {
            v.push_back({x, 1});
        }
    }
};

inline bool operator != (const Node &l, const Node &r) {
    if (l.v.size() != r.v.size()) return true;
    int n = l.v.size();
    for (int i = 0; i < n; i++) {
        if (l.v[i] != r.v[i]) return true;
    }
    return false;
}
inline bool operator < (const Node &l, const Node &r) {
    int n = min(l.v.size(), r.v.size());
    for (int i = 0; i < n; i++) {
        if (l.v[i][0] != r.v[i][0]) return l.v[i][0] > r.v[i][0];
        else if (l.v[i][1] != r.v[i][1]) return l.v[i][1] < r.v[i][1];
    }
    return (l.v.size() != r.v.size()) ? l.v.size() < r.v.size() : 0;
}

inline Node merge(const Node &l, const Node &r) {
    Node f;
    int n = l.v.size(), m = r.v.size();
    for (int i = 0, j = 0; i < n || j < m;) {
        if (j == m || (i < n && l.v[i][0] < r.v[j][0])) {
            f.v.push_back(l.v[i]);
            i++;
        } else if (i == n || (j < m && l.v[i][0] > r.v[j][0])) {
            f.v.push_back(r.v[j]);
            j++;
        } else {
            f.v.push_back({l.v[i][0], l.v[i][1] + r.v[j][1]});
            i++, j++;
        }
    }
    return f;
}

Node a[N], b[N];
void solve(){
    int n, m;cin >> n >> m;
    ll q;cin >> q;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        a[i] = Node(x);
    }
    for (int i = 1; i <= m; i++) {
        int x;cin >> x;
        b[i] = Node(x);
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    
    // int k = 1;
    // for (int i = 2; i <= n; i++) {
    //     if (a[i] != a[k]) a[++k] = a[i];
    //     else a[k].cnt++;
    // }
    // n = k;

    // k = 1;
    // for (int i = 2; i <= m; i++) {
    //     if (b[i] != b[k]) b[++k] = b[i];
    //     else b[k].cnt++;
    // }
    // m = k;
    
    vector<int> pre(m + 1);
    for (int i = 1; i <= m; i++) {
        pre[i] = pre[i - 1] + b[i].cnt;
    }
    mt19937 Rand(9999);
    vector<Node> c(n + 1);
    for (int i = 1; i <= n; i++) {
        int p = Rand() % n + 1, q = Rand() % m + 1;
        c[i] = merge(a[p], b[q]);
    }
    sort(c.begin() + 1, c.end());
    vector<int> cp(n + 1);

    auto check = [&](Node &x) -> ll{
        ll res = 0;
        for (int i = n, j = 1; i >= 1; i--) {
            for (;j <= m && !(x < merge(a[i], b[j])); j++);
            res += 1ll * a[i].cnt * pre[(cp[i] = j) - 1];
        }
        return res;
    };

    int l = 0, r = n;
    while (l < r) {
        int m = l + r + 1 >> 1;
        if (check(c[m]) >= q) r = m - 1;
        else l = m;
    }
    if (!r) {
        for (int i = 1; i <= n; i++) cp[i] = 1;
    }else {
        check(c[r]);
    }
    priority_queue<pair<Node, int>, vector<pair<Node, int>>, greater<pair<Node,int>>> que;
    for (int i = 1; i <= n; i++) {
        q -= 1ll * a[i].cnt * pre[cp[i] - 1];
        if (cp[i] != m + 1) que.push({merge(a[i], b[cp[i]]), i});
    }
    assert(q > 0);
    Node lsh(0);
    while (!que.empty()) {
        lsh = que.top().first;
        int id = que.top().second;
        que.pop();

        q -= 1ll * a[id].cnt * b[cp[id]].cnt;
        if (q <= 0) break;
        cp[id]++;
        if (cp[id] != m + 1) que.push({merge(a[id], b[cp[id]]), id});
    }
    ll ans = 1;
    for (auto [x, y] : lsh.v) {
        while (y) {
            ans *= x;
            y--;
        }
    } 
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
