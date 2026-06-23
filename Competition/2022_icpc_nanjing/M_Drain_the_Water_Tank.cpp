#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define double long double

//vector<vector<int>>edg(N);

struct Point{
    double x,y;
    Point(){};
    Point(double x,double y):x(x),y(y){};

    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
 
    void print(){
        cout<<x<<" "<<y<<endl;
    }
};

typedef Point Vecotr;

double Cross(Vecotr A,Vecotr B){return A.x*B.y - A.y*B.x;}

void solve()
{
    int n;cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int l = (i - 1 + n) % n, r = (i + 1) % n;
        if (a[i].y >= a[l].y || a[i].y > a[r].y)continue;
        if (a[i].y < a[r].y) {
            if (Cross(a[i] - a[l], a[r] - a[i]) > 0) res++;
        }else {
            while (a[(r + 1) % n].y == a[r].y) r = (r + 1) % n;
            if (a[(r + 1) % n].y > a[r].y && a[r].x > a[i].x) res++;
        }
    }
    cout << res << '\n';

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}