#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

typedef double db;
const db eps = 1e-9;

inline int sign(db a){ return a < -eps ? -1 : a > eps;}
inline int cmp(db a, db b){return sign(a - b);}

struct P {
	int x, y;
    int w,id,ans;
    int i;
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
	void print(){ cout << "(" << x << "," << y << ")" << "\n";}
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
}p[N];  

int tr[N];

void add(int k, int x) {
    for(int i = k; i < N; i += i&-i) tr[i] += x;
}

int sum(int x) {
    int res = 0;
    for(int i = x; i; i -= i&-i) res += tr[i];
    return res;
}




void solve()
{
    int n,x;
    cin >> n >> x;
    for(int i = 1; i <= n;i ++) {
        cin >> p[i].x >> p[i].y >> p[i].w;
        p[i].id = i;
    }

    sort(p + 1 , p + n + 1, [&](P a, P b) {
        a.x -= x;
        b.x -= x;
        int qa = a.quad(), qb = b.quad();
        if(qa != qb) return qa < qb;
        else return sign(a.det(b)) > 0;
    });

    
    reverse(p+1,p+n+1);

    for(int i=1;i<=n;i++){
        p[i].i = i;
        add(i, p[i].w);
        // p[i].print();
    }

    sort(p + 1 , p + n + 1, [&](P a, P b) {
        int qa = a.quad(), qb = b.quad();
        if(qa != qb) return qa < qb;
        else return sign(a.det(b)) > 0;
    });
    reverse(p+1,p+n+1);

    for(int i=1;i<=n;i++){
        add(p[i].i, - p[i].w);
        p[i].ans = sum(p[i].i);
       
    }

    sort(p + 1 , p + n + 1, [&](P a, P b) {
        return a.id < b.id;
    });

    for(int i = 1; i <= n; i++) {
        cout << p[i].ans << endl;
    }
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