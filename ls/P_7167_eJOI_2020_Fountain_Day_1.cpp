#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n,d[N];
int c[N], rmax[N][20], f[N][20], g[N][20],log_2[N];

int query_max(int a, int b) {
    int x = log_2[b - a + 1];
    return max(rmax[a][x], rmax[b - (1 << x) + 1][x]);
}

void solve()
{
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> d[i] >> c[i];
    }

    for(int i = 2; i <= n; i ++) {
        log_2[i] = log_2[i >> 1] + 1;
    }

    for(int i = 1; i <= n; i ++) {
        rmax[i][0] = d[i];
    }

    for(int j = 1; (1 << j) <= n; j ++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i ++) {
            rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << j - 1)][j - 1]); 
        } 
    }
    c[n + 1] = INF;

    for(int i = 1; i <= n; i ++) {
        int l = i + 1, r = n + 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(query_max(i + 1, mid) <= d[i])l = mid + 1;
            else r = mid;
        }

        f[i][0] = l; // next[i];
        g[i][0] = c[l];
    }

    for(int t = 1; t <= 19; t ++) {
        for(int i = 1; i <= n; i ++) {
            f[i][t] = f[f[i][t - 1]][t - 1];
            g[i][t] = g[i][t - 1] + g[f[i][t - 1]][t - 1];
        }
    }

    while(q -- ) {
        int r, v;
        cin >> r >> v;
        if(v > c[r]) {
            v -= c[r];
            for(int t = 19; t >= 0; t --) {
                if(v > g[r][t]) {
                    v -= g[r][t];
                    r = f[r][t];
                }
            }
            r = f[r][0];
        }

        if(r == n + 1) r = 0;
        cout << r << endl;
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