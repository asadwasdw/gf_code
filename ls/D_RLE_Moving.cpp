#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

typedef pair<char,int> PCI;



void solve()
{
    map<char,ll> dx;
    map<char,ll> dy;
    dx['U'] = -1;
    dx['D'] = 1;
    dy['L'] = -1;
    dy['R'] = 1; 
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    ll n, m, l;
    cin >> n >> m >> l;
    vector<PCI> s, t;

    for(int i = 0; i < m; i ++) {
        char a; ll b;
        cin >> a >> b;
        s.push_back({a, b});
    }

    for(int i = 0; i < m; i ++) {
        char a; ll b;
        cin >> a >> b;
        t.push_back({a, b});
    }

    ll ans = 0;

    auto calc = [&](int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) -> int {
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        if(x3 > x4) swap(x3, x4);
        if(y3 > y4) swap(y3, y4);

        if(x1 == x2 && x3 == x4) {
            if(x1 == x3) return max(0, min(y2, y4) - max(y1, y3));
            else return 0;
        } else if(y1 == y2 && y3 == y4) {
            if(y1 == y3) return max(0, min(x2, x4) - max(x1, x3));
            else return 0;
        } else {
            if(x1 != x2) {
                swap(x1, x3);
                swap(y1, y3);
                swap(x2, x4);
                swap(y2, y4);
            }
            int x = x1, y = y3;
            if(y1 <= y && y <= y2 && x3 <= x && x <= x4) return 1;
            else return 0;
        }
    };

    for(int i = 0; i < m; i ++) {
        ll sx2 = sx + dx[s[i].first] * s[i].second;
        ll sy2 = sy + dy[s[i].first] * s[i].second;
        ll tx2 = tx + dx[t[i].first] * t[i].second;
        ll ty2 = ty + dy[t[i].first] * t[i].second;
        // ans += calc(sx, sy, sx2, sy2, tx, ty, tx2, ty2);
        sx = sx2, sy = sy2, tx = tx2, ty = ty2;
    }
    cout << ans << endl;









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