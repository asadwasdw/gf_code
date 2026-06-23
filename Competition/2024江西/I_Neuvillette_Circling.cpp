#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

using db = long double;
constexpr db eps = 1e-9;
int sign(db a) {
    return a < -eps ? -1 : a > eps;
}
struct P {
    db x, y;
    P() {}
    P (db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) const {return {x + p.x, y + p.y};}
    P operator-(P p) const {return {x - p.x, y - p.y};} 
    P operator*(db d) const {return {x * d, y * d};}
    P operator/(db d) const {return {x / d, y / d};}
    void read() {cin >> x >> y;}
    void print() {
        cout << "( " << x << " " << y << ")\n";
    }
    db dot(P p) {return x * p.x + y * p.y;}
    db det(P p) {return x * p.y - y * p.x;}
    db distTo(P p) {return (*this - p).abs();}
    db abs() {return sqrtl(abs2());}
    db abs2() {return x * x + y * y;}
    P rot90() {return P(-y, x);}
};
db cross (P p1, P p2, P p3) {
    return P(p2 - p1).det(P(p3 - p1));
}
P isLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1 * a2 + p2 * a1) / (a1 + a2);
}

P getmid(P p1, P p2, P p3) {
    P m1 = (p1 + p2) / 2;
    P m2 = (p2 + p3) / 2;
    P fx1 = p2 - p1;
    P fx2 = p3 - p2;
    fx1 = fx1.rot90();
    fx2 = fx2.rot90();
    P m12 = m1 + fx1, m22 = m2 + fx2;
    return isLL(m1, m12, m2, m22);
}

void solve()
{
    int n; cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++) p[i].read();

    vector<db> cnt(n + 10, 1e12);
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if (sign(cross(p[i], p[j], p[k])) == 0) continue;
            P mid = getmid(p[i], p[j], p[k]);
            int tmp = 0;
            db dis = mid.distTo(p[i]);
            for (int l = 0; l < n; l++) {
                if (sign(dis - mid.distTo(p[l])) >= 0) tmp++;
            }
            // cout << tmp << endl;
            // if (tmp == 4) {
            //     p[i].print(), p[j].print(), p[k].print();
            //     mid.print();
            //     for (int l = 0; l < n; l++) {
            //         cout << dis << ' ' << mid.distTo(p[l]) << '\n';
            //     }
            // }
            cnt[tmp] = min(cnt[tmp], dis);
        }


        P mid = (p[i] + p[j]) / 2;
        int tmp = 0;
        db dis = mid.distTo(p[i]);
        for (int l = 0; l < n; l++) {
            if (sign(dis - mid.distTo(p[l])) >= 0) tmp++;
        }
        // cout << tmp << " "<< dis << endl;
        cnt[tmp] = min(cnt[tmp], dis);
    }

    for(int i = n - 1; i >=1; i --) {
        cnt[i] = min(cnt[i], cnt[i + 1]);
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << i << " " << cnt[i] << endl;
    // } 
    int j = 1;
    for(int i = 1; i <= n * (n - 1)/ 2; i ++) {
        if(j * (j - 1) < i * 2) j ++;
        // cout << i << " " << j << endl;
        cout << cnt[j] << endl;
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