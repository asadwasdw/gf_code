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
constexpr int N=150000+10, M=1e6+10;
constexpr int mod=998244353;
constexpr double eps=1e-9;
int nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0};


int n,m;
int a[N];
vector<P> dai[N];
int pre[M], cur[M];


vector<P> g[N], q[N];
constexpr int B = 400;
int id[N], L[N], R[N];
vector<int> SUM;
vector<vector<int>> sum;
void init(){
    for(int i=1; i<=n; ++i){
        id[i] = (i-1) / B + 1;
    }
    for(int i=1; i<=id[n]; ++i){
        L[i] = (i-1) * B + 1;
        R[i] = min(n, i * B);
    }
    SUM.resize(id[n]+10);
    sum.resize(id[n]+10);
    for(int i=0; i<=id[n]; ++i)sum[i].resize(R[i] - L[i] + 10);
}

void update(int y, int w){
    sum[id[y]][y - L[id[y]] + 1] = max(sum[id[y]][y - L[id[y]] + 1], w);
    SUM[id[y]] = max(SUM[id[y]], w);
}

int query(int x){
    int res = 0;
    for(int i=1; i<id[x]; ++i)res = max(res, SUM[i]);
    for(int i=L[id[x]]; i<=x; ++i)res = max(res, sum[id[x]][i - L[id[x]] + 1]);
    return res;
}


void solve(){
    cin >> n >> m;
    init();

    auto add = [&](int x, int pos){
        if(pre[x]){
            if(pos * 2 - pre[x] <= n)
            dai[pos * 2 - pre[x]].push_back({pre[x], x});
            // cout << pre[x] << ' ' << pos * 2 - pre[x] << ' ' << x << endl;
        }
        pre[x] = pos;
        if(cur[x]){
            g[cur[x]].push_back({pos, x});
            cur[x] = 0;
            // cout << cur[x] << ' ' << pos << ' ' << x << endl;
        }
    };
    
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        for(auto [l, y] : dai[i]){
            cur[y] = max(cur[y], l);
        }
        dai[i].clear();
        for(int j=1; j*j<=a[i]; ++j){
            if(a[i] % j == 0){
                int k = a[i] / j;
                add(j, i);
                if(j != k)
                add(k, i);
            }
        }
    }
    // for(int i=1; i<=n; ++i){
    //     if(g[i].size()){
    //         for(auto [y, w] : g[i])cout << i << ' ' << y << ' ' << w << endl;
    //     }
    // }
    for(int i=1; i<=m; ++i){
        int l,r;
        cin >> l >> r;
        q[l].push_back({r, i});
    }
    vector<int> res(m+1);
    for(int i=n; i>=1; --i){
        for(auto [y, w] : g[i]){
            update(y, w);
        }
        for(auto [r, id] : q[i]){
            res[id] = query(r);
        }
    }
    for(int i=1; i<=m; ++i)cout << res[i] << endl;



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
