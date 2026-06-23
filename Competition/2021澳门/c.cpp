#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define double long double
//vector<vector<int>>edg(N);

const double pi = acos(-1.0);
const double eps = 1e-6;

int sgn(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0?-1:1;
}


struct Point {
    double x, y;
    Point(){};
    Point(double x, double y) :x(x),y(y){};

    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    int quad() {
        return ((sgn(y)) == 1 || (sgn(y) == 0 && sgn(x) >= 0));
    }

    void print(){
        cout<<x<<" "<<y<<endl;
    }
}p[N];

typedef Point Vector;//向量和点的表示方法一样

double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}

bool cmpjj(Point a, Point b) {
    int qa = a.quad(), qb = b.quad();
    if(qa != qb) return qa < qb;
    else return sgn(Cross(a, b)) > 0;
}


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x, y;cin >> x >> y;
        p[i] = Point(x, y);
        // cin >> p[i].x >> p[i].y;
    }

    sort(p + 1, p + n + 1, cmpjj);
    for(int i = 1; i <= n; i ++) {
        p[i + n] = p[i];
        // p[i].print();
    }
    int i = 1, j = 1;
    int ans = n;
    for(;i <= n; i ++) {
        while(j < i + n && Cross(p[i],p[j]) >= 0) j ++;
        ans = min({ans, j - i, n - (j - i)});
        // cout << i << " " << j << endl;
    }
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}