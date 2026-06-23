#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

using db = long double;
const db eps = 1e-9;
const db PI = acos(-1);
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
	db abs() { return sqrt(abs2()); }
	db abs2() { return x * x + y * y; }
	P rot90() { return P(-y, x); }
	P unit() { return *this/abs(); }
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
	P rot(db an){ return {x*cos(an) - y*sin(an), x*sin(an) + y*cos(an)}; }
};  

// p1p2 × p1p3
db cross(P p1, P p2, P p3){ return P(p2 - p1).det(P(p3 - p1)); }
db crossOp(P p1, P p2, P p3){ return sign(cross(p1, p2, p3)); }//可能有精度问题

// 直线p1p2，q1q2是否恰有一个交点
bool chkLL(P p1, P p2, P q1, P q2){
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return sign(a1 + a2) != 0;
}

//求直线p1p2, q1q2的交点
P isLL(P p1, P p2, P q1, P q2){
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}


void solve()
{
    int R; cin >> R;
    int n = 5;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    db ans = 0;

    db S = PI * R * R;
    auto calc = [&](int l, int r, int ll, int rr) -> db {
        P pl(R * cosl(PI / 180 * l), R * sinl(PI / 180 * l));
        P pr(R * cosl(PI / 180 * r), R * sinl(PI / 180 * r));
        P ql(R * cosl(PI / 180 * ll), R * sinl(PI / 180 * ll));
        P qr(R * cosl(PI / 180 * rr), R * sinl(PI / 180 * rr));
        P m = isLL(ql, pr, pl, qr);
        db s1 = cross(P(0, 0), pl, pr) / 2;
        db s2 = cross(m, pl, pr) / 2;
        return S * ((r - l + 360) % 360) / 360 - s1 + s2;
    };

    for (int i = 0; i < n; i++) {
        ans += calc(t[i], s[(i + 1) % n], t[(i - 1 + n) % n], s[(i + 2) % n]);
    }
    ans = S - ans;
    cout << ans << '\n';



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(9) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}