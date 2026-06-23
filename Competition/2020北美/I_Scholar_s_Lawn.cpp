#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const ll INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
typedef long double db;
const double pi =acos(-1.0);
const db eps = 1e-8;

int sgn(double x){
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}

struct Point {
    db x, y;
    Point(){};
    Point(db x, db y) :x(x),y(y){};

    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (db k){return Point(x*k,y*k);}
    Point operator / (db k){return Point(x/k,y/k);}
    bool operator == (Point B){return sgn(x-B.x)==0&&sgn(y-B.y)==0;}
    bool operator < (Point B) { if(sgn(x - B.x)) return x < B.x; return y < B.y;}
    void print(){
        cout<<x<<" "<<y<<endl;
    }
}P[N * N];

double Distance(Point A,Point B){
    return hypot(A.x-B.x,A.y-B.y);
}


struct Line{
    Point p1,p2;
    Line(){};
    Line(Point p1,Point p2):p1(p1),p2(p2){
        // if(p1.x>p2.x) swap(this->p1,this->p2);//保证方向向右,
    };

    Line (Point p, double angle){
        p1=p;
        if(sgn(angle-pi/2)==0){p2=p1+Point(0,1);}
        else p2 = (p1+Point(1,tan(angle)));
    }

    Line(double a,double b,double c){   /// ax+by+c=0
        if(sgn(a)==0){
            p1=Point(0,-c/b);
            p2=Point(2,-c/b);
        }
        else if(sgn(b)==0){
            p1=Point(-c/a,0);
            p2=Point(-c/a,1);
        }
        else {
            p1=Point(0,-c/b);
            p2=Point(1,(-c-a)/b);
        }
    }
};

typedef Point Vector;//向量和点的表示方法一样

double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}


Point Cross_point(Point a,Point b,Point c,Point d){ // 直线交点
    double s1 = Cross(b-a,c-a);
    double s2 = Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
}

Point Cross_point(Line a, Line b) {
    return Cross_point(a.p1, a.p2, b.p1, b.p2);
}

bool Cross_segment(Point a,Point b,Point c,Point d){ // 线段相交
    double c1 = Cross(b-a,c-a);
    double c2 = Cross(b-a,d-a); // cd在两侧
    double c3 = Cross(d-c,a-c);
    double c4 = Cross(d-c,b-c); // ab在两侧
    return sgn(c1)*sgn(c2)<0&&sgn(c3)*sgn(c4)<0;
}

bool Cross_segment(Line a, Line b) {
    return Cross_segment(a.p1, a.p2, b.p1, b.p2);
} 




//vector<vector<int>>edg(N);
int n,m;
struct {
    Line L;
    vector<Point>d;
    vector<int>id;
}p[N];
int ans[N];
vector<pair<int,db> > edg[N*N];
int cnt = 1;



double Dot(Vector A,Vector B){//向量A,B的点积
    return A.x*B.x+A.y*B.y;
}

bool Point_on_seg(Point p,Line v){
    return sgn(Cross(p-v.p1,v.p2-v.p1)) == 0 && sgn(Dot(p-v.p1,p-v.p2)) <= 0;
}

bool isans[N*N];
bool st[N*N];
db DIS[N*N];

void addnode(int i, Point x) {
    ++cnt;
    p[i].d.push_back(x);
    p[i].id.push_back(cnt);
    P[cnt] = x;
    DIS[cnt] = INF;
}

void add(int u, int v, db x) {
    // cout << u << " " << v << " " << x << endl;
    edg[u].push_back({v, x});
    edg[v].push_back({u, x});
}
void solve()
{
    cin >> n;
    
    Point x,y;
    for(int i = 1; i <= n; i ++) {
        cin >> x.x >> x.y >> y.x >> y.y;
        p[i].L = Line(x,y);

        addnode(i,x);
        addnode(i,y);
    }

   
    double v1,v2;
    Point s;
    cin >> s.x >> s.y >> v1;
    Line t;
    cin >> x.x >> x.y >> y.x >> y.y >> v2;
    // cout << Point_on_seg(s,p[3].L) << endl;
    t = Line(x,y);
    for(int i = 1; i <= n; i ++) {
        p[i].L;
        ans[i] = -1;
        if(Cross_segment(p[i].L,t)) {
            ++cnt;
            Point T = Cross_point(p[i].L, t);
            ans[i] = cnt;
            p[i].d.push_back(T);
            p[i].id.push_back(cnt);
            P[cnt] = T;
            isans[cnt] = true;
            DIS[cnt] = INF;
        }

        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            if(Cross_segment(p[i].L,p[j].L)) {
                Point T = Cross_point(p[i].L, p[j].L);
                addnode(i,T);
                addnode(j,T);
                add(cnt,cnt-1,0);
            }
        }

        if(Point_on_seg(s,p[i].L)) {
            // cout << " s"<<endl;
            p[i].id.push_back(1);
            p[i].d.push_back(s);
        }


        for(int x = 0; x < p[i].d.size(); x ++ ) {
            for(int y = x + 1; y < p[i].d.size(); y ++) {
                add(p[i].id[x], p[i].id[y], Distance(p[i].d[x],p[i].d[y]));
            }
        }
    }

    priority_queue<pair<db,int>,vector<pair<db,int>>, greater<pair<db,int>>>q;
    q.push({0,1});
    db res = INF;
    while(q.size()) {
        auto [dis, u] = q.top(); q.pop();
        // cout << u << endl;
        if(st[u]) continue;
        st[u] = true;
        if(isans[u]) {
            db ti = Distance(P[u],t.p1)/v2;
            if(dis/v1 < ti || sgn(ti - dis/v1) == 0)  res = ti/v2;
        }

        for(auto [v, w] : edg[u]) {
            if(dis + w < DIS[v]) {
                DIS[v] = dis + w;
                q.push({DIS[v],v});
            }
        }
    }
    if(res < INF)cout << res << endl;
    else cout << "-1";
    // cout << "debug" << endl;
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