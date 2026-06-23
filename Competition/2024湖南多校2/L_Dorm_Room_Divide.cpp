#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
typedef long double db;
const __float128 eps = 1e-30;

inline int sign(__float128 a){ return a < -eps ? -1 : a > eps;}

struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator-(P p) { return {x - p.x, y - p.y}; }

	void read() { cin >> x >> y; }
	db det(P p) { return x * p.y - y * p.x; }
};  

// p1p2 × p1p3
db cross(P p1, P p2, P p3){ return P(p2 - p1).det(P(p3 - p1)); }

db area(vector<P> ps){
	db ret = 0; for(int i = 0; i < ps.size(); i++) {
        ret += ps[i].det(ps[(i + 1) % ps.size()]);
        // cout  << ret << endl;
    }
	return ret;
}

void solve()
{
    int n;cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++) p[i].read();

    db S = area(p);
    db s = 0;
    int pr = 0;
    for (int i = 2; i < n; i++) {
        s += cross(p[0], p[i - 1], p[i]);
        if (2 * s > S) {
            pr = i;
            s -= cross(p[0], p[i - 1], p[i]);
            break;
        }
    }
    int pl = pr - 1;

    db s1 = cross(p[0], p[pl], p[pr]);
    auto check = [&](__float128 dis) ->bool {
        return sign(2 * s + 2 * s1 * dis - S) > 0;
    };

    __float128 l = 0, r = 1.0; 
    while ((r - l) >= eps) {
        __float128 m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << (long double)(p[pl].x + (p[pr].x - p[pl].x) * l) << ' ';
    cout << (long double)(p[pl].y + (p[pr].y - p[pl].y) * l) << '\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(9) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}