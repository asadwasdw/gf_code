#include<bits/stdc++.h>
using i64 = long long;

inline i64 sign(i64 a) {
    return a < 0 ? -1 : a > 0;
}
struct P {
    i64 x, y;
    P () {}
    P (i64 _x, i64 _y) : x(_x), y(_y) {}
    P operator+(P p) const { return {x + p.x, y + p.y};}
    P operator-(P p) const { return {x - p.x, y - p.y};}
    P operator*(i64 d) const {return {x * d, y * d};}
    bool operator<(P p) const {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
    bool operator==(P p) const {
        return x == p.x && y == p.y;
    }
    void read() {std::cin >> x >> y;}
    i64 dot(P p ) {return x * p.x + y * p.y;}
    i64 det(P p) {return x * p.y - y * p.x;}
};
i64 cross(P p1, P p2, P p3) {
    return P (p2 - p1).det(P(p3 - p1));
}
i64 crossOp(P p1, P p2, P p3) {
    return sign(cross(p1, p2, p3));
}
i64 area(std::vector<P> ps) {
    i64 ret = 0;
    for (int i = 0; i < ps.size(); i++) ret += ps[i].det(ps[(i + 1) % ps.size()]);
    return ret;
}
std::vector<P> convexHull(std::vector<P> ps) {
    int n = ps.size(); if (n <= 1) return ps;
    sort(ps.begin(), ps.end());
    std::vector<P> qs(n * 2); int k = 0;
    for (int i = 0; i < n; qs[k++] = ps[i++])
        while(k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while(k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
    qs.resize(k - 1);
    return qs;
}
void solve() {
    int n; std::cin >> n;
    std::vector<P> p1(n);
    for (int i = 0; i < n; i++) p1[i].read();
    auto h1 = convexHull(p1);
    std::set<P> st(h1.begin(), h1.end());
    std::vector<P> p2;
    for (auto p : p1) {
        if (!st.count(p)) p2.push_back(p);
    }
    auto h2 = convexHull(p2);
    if (h2.empty()) {
        std::cout << -1 << "\n";
        return;
    }
    n = h1.size();
    int m = h2.size();
    i64 mi = 8e18;
    if (m == 1) {
        for (int i = 0, j = 0; i < n; i++) {
            mi = std::min(mi, cross(h2[j], h1[i], h1[(i + 1) % n]));
        }
    } else {

        for (int i = 0, j = 0; i < n; i++) {
            while(cross(h2[j], h1[i], h1[(i + 1) % n]) >= cross(h2[(j + 1) % m], h1[i], h1[(i + 1) % n])) j = (j + 1) % m;
            while(cross(h2[(j - 1 + m) % m], h1[i], h1[(i + 1) % n]) < cross(h2[j], h1[i], h1[(i + 1) % n])) j = (j - 1 + m) % m;
            mi = std::min(mi, cross(h2[j], h1[i], h1[(i + 1) % n]));
        }
    }
    // int be = 0;
    // for (int i = 0; i < n; i++) {
    //     if (cross(h2[0], h1[i], h1[(i + 1) % n]) <= mi) {
    //         mi = cross(h2[0], h1[i], h1[(i + 1) % n]);
    //         be = i;
    //     }    
    // }
    // for (int i = be, j = 0; j < m; j++) {
    //     while (cross(h2[j], h1[(i + 1) % n], h1[(i + 2) % n]) <= cross(h2[j], h1[(i) % n], h1[(i + 1) % n])) i = (i + 1) % n;
    //     while (cross(h2[j], h1[(i) % n], h1[(i + 1) % n]) > cross(h2[j], h1[(i - 1 + n) % n], h1[(i) % n])) i = (i - 1 + n) % n;
    //     mi = std::min(mi, cross(h2[j], h1[(i) % n], h1[(i + 1) % n]));
    // }
    std::cout << area(h1) - mi << "\n";
}


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    std::cout << std::setprecision(11) << std::fixed;
    int t;t=1;
    std::cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}