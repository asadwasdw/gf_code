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
int x, y, p, q;
int ans = 0;
map<PII,int> l, r;


int dfsl(int lx, int ly);
int dfsr(int lx, int ly);

int dfsl(int lx, int ly) {
    if(l[{lx, ly}]) return l[{lx, ly}];

    int rx = x - lx, ry = y - ly;
    cout  << "l " << lx << " " << ly << endl;

    int res = INF;
    for(int i = 0; i <= lx; i ++) {
        for(int j = 0; j <= ly; j ++) {
            if(i + j > p) continue;

            if(lx - i && (ly - j) > (lx - i) + q) continue;
            if(i == j && i == 0) continue;
            if(lx - i < 0 || ly - j < 0) continue;
            res = min(res, dfsr(lx - i, ly - j) + 1);
        }
    }
    return l[{lx, ly}] = res;
}


int dfsr(int lx, int ly) {
    int rx = x - lx, ry = y - ly;
    cout  << "r " << lx << " " << ly << endl;
    if(lx == 0) {
        return 0;
    }

    if(r[{lx, ly}]) return r[{lx, ly}];
    int res = INF;

    for(int i = 0; i <= rx; i ++) {
        for(int j = 0; j <= ry; j ++) {
            if(i + j > p) continue;

            if(rx - i && (ry - j) > (rx - i) + q) continue;
            if(lx + i > x || ly + j > y) continue;
            res = min(res, dfsl(lx + i, ly + j));
        }
    }
    return r[{lx, ly}] = res;
}



void solve()
{
    cin >> x >> y >> p >> q;
    cout << dfsl(x, y);
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