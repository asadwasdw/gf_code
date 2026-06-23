// #pragma GCC optimize(2)
#include<bits/stdc++.h>
#define endl '\n'
#define lowbits(x) ((x)&((-x)))
#define INF 0x3f3f3f3f
#define uu __int128
#define PI acos(-1)
#define ls k<<1
#define rs k<<1|1
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PII;
constexpr int N=2e3+10, M=2*N;
constexpr int mod=998244353;
constexpr double eps=1e-9;
int nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0};


int n,m;


int a[N][N];

bool vis[N][N];

void f(int x1, int y1, int x2, int y2, int n) {
    int dx = (x1 - x2);
    int dy = (y1 - y2);
    int dd = a[abs(dx)][abs(dy)];
    if(dx < 0)dd *= -1;
    dx /= dd, dy /= dd;
    int x = x1, y = y1;
    while(1 <= x && x <= n && 1 <= y && y <= n) {
        vis[x][y] = true;
        x += dx, y += dy;
    }
    x = x1, y = y1;
    while(1 <= x && x <= n && 1 <= y && y <= n) {
        vis[x][y] = true;
        x -= dx, y -= dy;
    }
}

void solve(){
    cin >> n;
    for(int i=0; i<=n; ++i)for(int j=0; j<=n; ++j){
        if(i == 0)a[i][j] = j;
        else if(j == 0)a[i][j] = i;
        else a[i][j] = __gcd(i, j);
    }
    vector<P> p;
    for(int i=1; i<=n*n; ++i){
        int x,y;
        cin >> x >> y;
        if(vis[x][y]){
            cout << '0';
            continue;
        }
        for(auto &[l, r] : p){
            f(l, r, x, y, n);
        }
        cout << '1';
        p.push_back({x, y});

    }



}


signed main()
{   
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t = 1;
    // cout << fixed << setprecision(9)
    // cin >> t;
    while(t--)solve();
    return 0;

}
