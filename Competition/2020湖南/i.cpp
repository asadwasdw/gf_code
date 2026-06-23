#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e6+10, mod = 1e9+7;
using i64 = long long;
// struct P {
//     i64 x, y;
//     P () {}
//     P (i64 _x, i64 _y) : x(_x), y(_y) {}
//     P operator+(P p) const {return {x + p.x, y + p.y};}
//     P operator-(P p) const {return {x - p.x, y - p.y};}
    
//     P operator*(i64 d) const {return {x * d, y * d};}
//     P operator/(i64 d) const {return {x / d, y / d};}
    
//     i64 dot(P p) { return x * p.x + y * p.y;}
//     i64 det(P p) { return x * p.y - y * p.x;}
// };
// i64 cross(P p1, P p2, P p3) { return P(p2 - p1).det(P(p3 - p1));}

// P isLL(P p1, P p2, P q1, P q2) {
//     i64 a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
//     return (q1 * a2 + p2 * a1) / (a1 + a2);
// }
constexpr i64 inf = 8e18;
void solve(){
    array<i64, 3> a, b, y;
    while (cin >> a[0] >> b[0] >> y[0] >> a[1] >> b[1] >> y[1] >>a[2] >> b[2] >> y[2]) {
        i64 l = inf, r = -inf;
        auto calc = [&](i64 p1, i64 p2) -> void {
            i64 val = (y[2] - y[0]) * (p2 - p1) + p1 * (y[1] - y[0]);
            l = min(l, val);
            r = max(r, val);
        };
        a[2] = a[2] * (y[1] - y[0]);
        b[2] = b[2] * (y[1] - y[0]);
        calc(a[0], a[1]);
        calc(a[0], b[1]);
        calc(b[0], a[1]);
        calc(b[0], b[1]);
        // cerr << l << ' ' << r << "\n";
        // cerr << a[2] << ' ' << b[2] << "\n";
        if (l > b[2] || r < a[2]) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}