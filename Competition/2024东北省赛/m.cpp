#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
typedef long double db;
const db pi = acos(-1.0);
const db eps = 1e-6;

int sgn(db x) {
    if(fabs(x) < eps) return 0;
    else return x < 0? -1 : 1;
}

struct Point
{
    ll x, y;
    Point(){};
    Point(ll x, ll y):x(x),y(y){};

    Point operator + (Point B) {return Point(x + B.x, y + B.y);}
    Point operator - (Point B) {return Point(x - B.x, y - B.y);}
    Point operator * (__float128 k){return Point(x*k,y*k);}
    bool operator == (Point B){return sgn(x-B.x)==0&&sgn(y-B.y)==0;}

    void print() {
        cout << "{" << x << "," << y <<"}\n";
    }
};

typedef Point Vector;

struct Line {
    Point p1,p2;
    Line(){};
    Line(Point p1, Point p2) : p1(p1), p2(p2) {};
};

Point p[350];
ll Dot(Vector A, Vector B) {
    return (ll)A.x * B.x + A.y * B.y;
}

ll Len2(Vector A)  {
    return Dot(A,A);
}

Point Point_line_proj(Point p, Line v) {
    db k = Dot(v.p2 - v.p1, p - v.p1) /(db) Len2(v.p2 - v.p1);
    return v.p1 + (v.p2 - v.p1) * k;
}



ll Cross(Vector A, Vector B) {
    return (ll)A.x * B.y - A.y * B.x;
}

int Line_relation(Line v1, Line v2) {
    if(sgn(Cross(v1.p2 - v1.p1, v2.p2 - v2.p1)) == 0) {
        return 0;
    }
    return 2;
}

map<PII,int> st;

int Poine_line_relation(Point p, Line v) {
    int c = sgn(Cross(p - v.p1, v.p2 - v.p1));
    if(c < 0) return 1;
    if(c > 0) return 2;
    return 0;
}

Vector Rotate(Vector A) {
    return Vector(- A.y, A.x);
}

Point Point_line_symmetry(Point p, Line v) {
    Point q = Point_line_proj(p, v);
    return Point(2 * q.x - p.x, 2 * q.y - p.y);
}

bool check(Point i, Point j, Point k) {
    Vector ij = j - i, ik = k - i;
    
    Line K = Line(k, k + ij);    
    Point i2 = Point_line_symmetry(i, K), j2 = Point_line_symmetry(j, K);

    int x1 = i2.x, y1 = i2.y, x2 = j2.x, Y2 = j2.y;
    if(i == i2 || j == j2) return false;
    if(sgn(i2.x - x1) || sgn(i2.y - y1) || sgn(j2.x - x2) || sgn(j2.y - Y2)) return false;
    if(!st[{x1,y1}] ||  !st[{x2,Y2}]) return false;
    if(Dot(j - i, k - i) >= 0) return false;

    return true;
}




void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) {
        int x, y;
        cin >> x >> y;
        st[{x,y}] ++;
        p[i] = Point(x,y);
    }

    int ans = 0;

    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= n; j ++) {
            for(int k = 1; k <= n; k ++) {
                if(i == j || j == k || i == k) continue;
                if(check(p[i], p[k], p[j])) {
                    // cout << i << " " << j << " " << k << endl;
                    // cout << Cross(p[j] - p[i], p[k] - p[i]) << endl; 
                    ans ++;
                }
            }
        }
    }

    cout << ans/2;
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