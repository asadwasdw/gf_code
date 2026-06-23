#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

using db = long double;
const db eps = 1e-12;

inline int sign(db a){ return a < -eps ? -1 : a > eps;}
inline int cmp(db a, db b){return sign(a - b);}

struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) const { return {x + p.x, y + p.y}; }
	P operator-(P p) const { return {x - p.x, y - p.y}; }
	P operator*(db d) const { return {x * d, y * d}; }
	P operator/(db d) const { return {x / d, y / d};}

	bool operator<(P p) const {
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == 1;
	}

	bool operator==(P p) const {
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
	}
	void read() { cin >> x >> y; }
	void print(){ cout << "(" << x << "," << y << ")" << " ";}
	db dot(P p) { return x * p.x + y * p.y; }
	db det(P p) { return x * p.y - y * p.x; }

	db distTo(P p) { return (*this - p).abs(); }
	db alpha() { return atan2(y, x); }
	db abs() { return sqrtl(abs2()); }
	db abs2() { return x * x + y * y; }
	P rot90() { return P(-y, x); }
	P unit() { return *this/abs(); }
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
	P rot(db an){ return {x*cos(an) - y*sin(an), x*sin(an) + y*cos(an)}; }
};  

// p1p2 × p1p3
db cross(P p1, P p2, P p3){ return P(p2 - p1).det(P(p3 - p1)); }
db crossOp(P p1, P p2, P p3){ return -sign(cross(p1, p2, p3)); }//可能有精度问题

//求直线p1p2, q1q2的交点
P isLL(P p1, P p2, P q1, P q2){
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}


void solve()
{

    int n, m; cin >> n >> m;
    vector<P> a(n), b(m);
    for (int i = 0; i < n; i++) a[i].read();
    for (int i = 0; i < m; i++) b[i].read();

    vector<db> len(n);
    vector<db> prelen(n);
    db sum = 0;
    for (int i = 0; i < n; i++) {
        len[i] = a[i].distTo(a[(i + 1) % n]);
        sum += len[i];
        prelen[i] = len[i];
        if (i) prelen[i] += prelen[i - 1];
    }

    int l, r;
    for (int i = 0; i < n; i++) {
        if (crossOp(b[0], b[1], a[i]) == 1 && crossOp(b[0], b[1], a[(i - 1 + n) % n]) == -1) l = i;
        if (crossOp(b[0], b[1], a[i]) == 1 && crossOp(b[0], b[1], a[(i + 1) % n]) == -1) r = i;
    }
    db ans = 0;
    for (int i = 0; i < m; i++) {
        while (crossOp(b[i], b[(i + 1) % m], a[l]) == -1) l = (l + 1) % n;
        while (crossOp(b[i], b[(i + 1) % m], a[(r + 1) % n]) == 1) r = (r + 1) % n;
        db now = 0;
        if (r < l) now = sum - (prelen[l] - prelen[r] - len[l] + len[r]);
        else now = prelen[r] - len[r] - prelen[l] + len[l];
        P p1 = isLL(b[i], b[(i + 1) % m], a[l], a[(l - 1 + n) % n]);
        P p2 = isLL(b[i], b[(i + 1) % m], a[r], a[(r + 1) % n]);
        now += a[l].distTo(p1) + a[r].distTo(p2);
        ans += b[i].distTo(b[(i + 1) % m]) * now / sum;  

    }
    cout << ans << '\n';

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(15) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}