#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
#define int long long
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

typedef long long db;
const db eps = 1e-9;

inline int sign(db a){ return a < -eps ? -1 : a > eps;}
inline int cmp(db a, db b){return sign(a - b);}

struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
	P operator/(db d) { return {x / d, y / d};}

	bool operator<(P p) const {
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}

	bool operator==(P p) const {
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
	}
	void read() { cin >> x >> y; }
	void print(){ cout << x << " " << y << "\n";}
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


void solve()
{
    int n;cin >> n;
    vector<P> point(n);
    for (int i = 0; i < n; i++) {
        point[i].read();
    }

    if (n < 5) {
        cout << "NO\n";
        return;
    }
    
    auto check = [&](int x) ->bool {
        vector<int> tmp{0, 1, 2, 3, x};
        
        for (int i = 0; i < 5; i++) {
            vector<P> s;
            for (int j = 0; j < 5; j++) {
                if (j == i)continue;
                s.push_back((point[tmp[j]] - point[tmp[i]]));
            }
            bool ok = true;
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if (l == k) continue;
                    if (s[k].det(s[l]) == 0 && (s[k].x * s[l].x >= 0 && s[k].y * s[l].y >= 0))
                        ok = false;
                }
            }

            if (ok) {
                cout << "YES\n";
                point[tmp[i]].print();
                for (int j = 0; j < 5; j++) {
                    if (j == i) continue;
                    point[tmp[j]].print();
                }
                return true;
            }
        }
        return false;
    };

    bool ok = false;
    for (int i = 4; i < n; i++) {
        if (check(i)) {

            ok = true;

            return;
        }
    }
    if (!ok) {
        cout << "NO\n";
    }



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}