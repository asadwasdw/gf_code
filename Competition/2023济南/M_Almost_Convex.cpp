#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

using db = long long;
const db eps = 0;
inline int sign(db a) {return a < -eps ? -1 : a > eps;}
inline int cmp(db a, db b) {return sign(a - b);}
struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) const {return {x + p.x, y + p.y};}
    P operator-(P p) const {return {x - p.x, y - p.y};}
    P operator*(db d) const {return {x * d, y * d};}
    P operator/(db d) const {return {x / d, y / d};}
    bool operator<(P p) const {
        int c = cmp(x, p.x);
        if (c) return c == -1;
        return cmp(y, p.y) == 1;
    }
    bool operator==(P p) const {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }
    void read() {cin >> x >> y;}
    void print() {cout << "( " << x << " , " << y << " )" << "\n";}
    db dot(P p) {return x * p.x + y * p.y;}
    db det(P p) {return x * p.y - y * p.x;}
    db distTo(P p) {return (*this - p).abs();}
    db abs() {return sqrt(abs2());}
    db abs2() {return x * x + y * y;}
    int quad() const {return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0);}
};

db cross(P p1, P p2, P p3) {
    return P(p2 - p1).det(P(p3 - p1));
}
int crossOp(P p1, P p2, P p3) {
    return sign(cross(p1, p2, p3));
}

vector<P> convexHull(vector<P> ps) {
    int n = ps.size(); 
    if (n <= 1) return ps;
    vector<P> qs(n * 2);
    int k = 0;
    for (int i = 0; i < n; qs[k++] = ps[i++])
        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    qs.resize(k - 1);
    return qs;
}



void solve()
{
    int n; cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++) p[i].read();
    sort(p.begin(), p.end());
    auto ps = convexHull(p);
    // for (auto x : ps) x.print();
    int ans = 1;
    vector<P> qs;
    int m = ps.size();
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (auto x : ps) {
            if (p[i] == x) {
                ok = false;
                break;
            }
        }
        if (ok) qs.push_back(p[i]);
    }
    n--;
    for (auto x : qs) {
        vector<pair<P, int>> tmp;
        for (auto y : ps) {
            tmp.push_back({y - x, 1});
        }
        for (auto y : qs) {
            if (y == x) continue;
            tmp.push_back({y - x, 0});
        }
        sort(tmp.begin(), tmp.end(), [&] (pair<P, int> &a, pair<P, int> &b) {
            int qa = a.first.quad(), qb = b.first.quad();
            if (qa != qb) return qa < qb;
            else return sign(a.first.det(b.first)) > 0;
        });
        int begin = 0;
        while (tmp[begin].second == 0) begin = (begin + 1) % n;
        int l = begin, r = begin + 1;
        bool ok = true;
        // for (int i = 0; i < n; i++) {
        //     (tmp[i].first + x).print();
        // }
        while (1) {
            if (tmp[r].second == 1) {
                // cout << l << ' ' << r << ' ' << ok << "\n";
                if (ok) ans++;
                l = r;
                ok = true;
                if (l == begin) break;
            } else {
                if (crossOp(x, tmp[l].first + x, tmp[r].first + x) != 0) ok = false; 
            }
            r = (r + 1) % n;
        }
        // cout << ans << '\n';
        // x.print();
        // cout << '\n';
    }
    cout << ans << '\n';




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}