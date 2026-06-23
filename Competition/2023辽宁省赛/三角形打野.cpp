#include<bits/stdc++.h>
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
#define db double

const db pi =acos(-1.0);
const db eps =1e-6;
int sgn(db x){
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
db pos(db k1,db x,db y){
	db b=y-k1*x;
	return -b/k1;
}
struct Point {
    db x, y;
    Point(){};
    Point(db x, db y):x(x),y(y){};

    Point operator + (Point B) {return Point(x + B.x, y + B.y);}
    Point operator - (Point B) {return Point(x - B.x, y - B.y);}
    Point operator * (db k) {return Point(x * k, y * k);}
    Point operator / (db k) {return Point(x / k, y / k);}

    bool operator == (Point B) {
        return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
    }

    void print() {
        cout << x << " " << y << endl;
    }
}O,A,B;

typedef Point Vector;

double Dot(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}

struct Line{
    Point p1, p2;
    Line(){};

    Line(Point p1,Point p2):p1(p1),p2(p2){
        // if(p1.x>p2.x) swap(this->p1,this->p2);//保证方向向右,
    };



    void print() {
        p1.print(); 
        p2.print();
        cout << endl; 
    }
};



Line a,b;
double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}

Point Cross_point(Point a,Point b,Point c,Point d){ // 直线交点
    double s1 = Cross(b-a,c-a);
    double s2 = Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
}

db check(db mid) {
    Point C = Point(mid, 0);
    Vector CA = A - C, CB = B - C;
    if(Cross(CA,CB) < 0)swap(CA, CB);

    Line line = Line(C, C + CA);
    // line.print();
    Point ta = Cross_point(line.p1,line.p2,a.p1,a.p2);
    Point tb = Cross_point(line.p1,line.p2,b.p1,b.p2);
    // return fabs(Dot(ta, tb));
    return ta.y * mid/2;

}



void solve()
{
    int X, Y;
    O = Point(0, 0);
    cin >> X >> Y;
    cin >> A.x >> A.y >> B.x >> B.y;

    a = Line(O, Point(Y, X));
    b = Line(O, Point(1, 0));

    double l = 0, r = 1e18;
    double k=X/Y;
	l=max(l,pos(k,A.x,A.y));
	l=max(l,pos(k,B.x,B.y));

    // cout << l << " " << r << endl;
    int cnt = 100;
    while(r - l > eps) {
        cnt --;
        // if(cnt == 0) break;
        double mid1 = l + (r - l)/3;
        double mid2 = l + (r - l)/3 * 2;

        // cout << l << " " << r << endl;

        if(check(mid1) < check(mid2)) {
            r = mid2;
        } else l = mid1;
    }
    cout << check(l) << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(6) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}