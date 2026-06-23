#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

typedef long double db;
//vector<vector<int>>edg(N);

struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) {return {x + p.x, y + p.y};}
    P operator-(P p) {return {x - p.x, y - p.y};}
    
    db distTo(P p) {return (*this - p).abs();}
    db abs() {return sqrtl(abs2());}
    db abs2() {return x * x + y * y;}
    void read() {cin >> x >> y;}
    void print() {cout << "(" << x << "," << y << ")\n";}
};

void solve()
{
    int n;cin >> n;
    string s;cin >> s;
    vector<P> a, b;
    for (int i = 0; i < n; i++) {
        P t; t.read();
        if (s[i] == 'G') a.push_back(t);
        else b.push_back(t);
    }

    db ans = 0;
    auto calc = [&](vector<P> p) -> void {
        int n = p.size();
        for (int i = 0; i < n / 2; i++) {
            ans += p[i].distTo(p[i + n / 2]);
        }
    };
    calc(a);
    calc(b);
    cout << ans << '\n'; 
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