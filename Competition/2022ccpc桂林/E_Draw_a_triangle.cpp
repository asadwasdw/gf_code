#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2 - x1, dy = y2 - y1;

    if (dx == 0) {
        cout << x1 + 1 << ' ' << y1 << '\n';
        return;
    }
    if (dy == 0) {
        cout << x1 << ' ' << y1 + 1 << '\n';
        return;
    }
    ll gd = abs(__gcd(dx, dy));
    dx /= gd, dy /= gd;
    
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    x2 = x1 + dx;
    y2 = y1 + dy;

    dx = abs(dx), dy = abs(dy);
    
    if (dx < dy) {
        cout << x2 << ' ' << y2 + 1 << '\n';
    }else {
        cout << x1 + 1 << ' ' << y1 << '\n';
    }



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}