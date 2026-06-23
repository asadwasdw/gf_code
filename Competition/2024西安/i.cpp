#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int a[N];

struct Node{
    int l, r, w;
}query[N];
int ans[N];

struct gfseg { // 区间最值
    int a[N], _n;
    struct Node {
        int l, r;
        int max;
    }tr[N];

    void pushup(int u) {
        tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
    }

    void build(int u, int l, int r) {
 
        if(l == r) {
            tr[u] = {l, r, a[l]};
            return;
        }
        int mid = l + r >> 1;
        tr[u] = {l, r, -INF};
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void init(vector<int> _a) {
        _n = _a.size();
        for(int i = 1; i <= _n; i ++) {
            a[i] = _a[i - 1];
        } 
        build(1, 1, _n);
    }

    void modify(int u, int x, int y) {
        if(tr[u].l == tr[u].r && tr[u].l == x) {
            tr[u].max = max(tr[u].max, y);
            return;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, y);
        if(x >  mid) modify(u << 1 | 1, x, y);
        pushup(u);
    }


    int querymax(int u, int l, int r) {
        if(l <= tr[u].l && tr[u].r <= r) {
            return tr[u].max;
        }

        int res = -INF;
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) res = max(querymax(u << 1, l,  r), res);
        if(r >  mid) res = max(querymax(u << 1 | 1, l,  r), res);
        return res;
    }

    void debug() {
        for(int i = 1; i <= _n; i ++)
        cout << querymax(1, i, i) << " "; cout <<  endl;
    }
}tr;


vector<Node> no2[N];
void solve()
{
    
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        // a[i] = rand();
        int x = a[i];
        for(int j = 1; j * j <= x; j ++) {
            if(x % j == 0) {
                adj[j].push_back(i);
                if(j * j != x) 
                    adj[x/j].push_back(i);
            }
        }
    }

    // for(auto t : adj[2]) cout << t << " "; cout << endl;


    for(int i = N-1; i >= 1; i --) {
        int l = adj[i].size() - 1, r = adj[i].size() - 1;
        for(; ~l; l --) {
            while((adj[i][l + 1] - adj[i][l] <= adj[i][r - 1] - adj[i][l + 1]) && r - 1 > l + 1) r --;
            // cout << l << " " << r << endl;
            if(r > l + 1 && (adj[i][l + 1] - adj[i][l] <= adj[i][r] - adj[i][l + 1])) {
                no2[adj[i][l]].push_back({adj[i][l], adj[i][r], i});
            }
        }
    }

    // for(int i = N - 1; i >= 1; i --) {
    //     for(int j = 0; j + 2 < adj[i].size(); j ++) {
    //         if(adj[i][j + 1] - adj[i][j] <= adj[i][j + 2] - adj[i][j + 1]) 
    //             no2[adj[i][j]].push_back({adj[i][j], adj[i][j + 2], i});
    //     }
    // }

    vector<int>T; for(int i = 1; i <= n + 10; i ++) T.push_back(0); tr.init(T);

    for(int i = 0; i < q; i ++) {
        cin >> query[i].l >> query[i].r; query[i].w = i;
    }

    sort(query , query + q, [&](Node a, Node b){
        return a.l > b.l;
    });

    vector<int>mx (n + 10, 0);
    int j = 0;
    for(int L = n; L >= 0; L --) {
        for(auto [x, y, w] : no2[L]){
            // cout << x << " " << y << " " << w << endl;
            if(mx[y] < w) {
                tr.modify(1, y, w);
                mx[y] = w;
            }
        }

        while(j < q && query[j].l >= L) {
            ans[query[j].w] = tr.querymax(1,1,query[j].r);
            j ++;
        }
    }
    // tr.debug();
    // cout << i << " " << j << endl;

    for(int i = 0; i < q; i ++) cout << ans[i] << endl;
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