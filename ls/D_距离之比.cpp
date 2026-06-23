#include<bits/stdc++.h>
#define end begin
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

#define db long double

const db pi = acos(-1.0);

struct Point {
    db x, y;
    Point(){};
    Point(db x, db y):x(x),y(y){};

    Point operator + (Point B){return Point(x + B.x, y + B.y);}
    Point operator - (Point B){return Point(x - B.x, y - B.y);}
    Point operator * (db k) {return Point(x*k, y*k);}
    Point operator / (db k) {return Point(x/k, y/k);}


    void print() {
        cout << "(" << x << "," << y <<")" << endl;
    }
};

typedef Point Vector;

Vector Rotate(Vector A, db rad) {
    return Vector(A.x*cosl(rad)-A.y*sinl(rad), A.x*sinl(rad) + A.y*cosl(rad));
}

db Dist(Point A, Point B) {
    return sqrtl((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}


typedef pair<Point,int>PII;

void solve()
{ 
    int n;
    cin >> n;
    vector<Point> p(n);
    vector<PII> p1(n), p2(n);
    for(int i = 0; i < n; i ++) {
        int x, y; cin >> x >> y;
        p[i] = Point(x, y);
    }

    auto calc = [&](int a, int b) -> db{
        db T1 = abs(p[a].x - p[b].x) + abs(p[a].y - p[b].y);
        db T2 = Dist(p[a], p[b]);
        return T1/T2;
    };


    db ans = 0;

    for(int k = 0; k < 8; k ++) {
        vector<PII> p1(n), p2(n);
        for(int i = 0; i < n; i ++) {
            p1[i] = {Rotate(p[i], -pi/4 * k), i};
            p2[i] = {Rotate(p[i], pi/4 * k), i};
        }
        sort(p1.begin(), p1.end(),[&](PII a, PII b){
            return a.first.x < b.first.x;
        });

        for(int i = 1; i < n; i ++) {
            ans = max(calc(p1[i].second, p1[i - 1].second), ans);
        }

        sort(p2.begin(), p2.end(),[&](PII a, PII b){
            return a.first.y < b.first.y;
        });

        for(int i = 1; i < n; i ++) {
            ans = max(calc(p2[i].second, p2[i - 1].second), ans);
        }
    }



    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(12) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}