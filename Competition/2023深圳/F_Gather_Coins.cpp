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

struct Node{
    int l, r;
    int w, id;
}tr[N<<2];



void pushup(int u) {
    // tr[u].w = max(tr[u<<1].w, tr[u<<1|1].w);
    if(tr[u<<1].w >= tr[u<<1|1].w) {
        tr[u].w = tr[u<<1].w;
        tr[u].id = tr[u<<1].id;
    }
    else {
        tr[u].w = tr[u<<1|1].w;
        tr[u].id = tr[u<<1|1].id; 
    }
}

void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, 0, 0};
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int k, int id) {
    if(tr[u].l == tr[u].r && tr[u].l == x) {
        // tr[u].w = max(tr[u].w, k);
        if(k >= tr[u].w) {
            tr[u].w = k;
            tr[u].id = id;
        }
        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid) modify(u << 1, x, k, id);
    if(x >= mid + 1) modify(u << 1|1, x, k, id);
    pushup(u);
}

PII query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        return {tr[u].w,tr[u].id};
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    int resid = 0;
    if(l <= mid) {
        PII t = query(u << 1, l, r);
        if(t.first >= res) {
            res = t.first;
            resid = t.second;
        }
    }
    if(r > mid)  {
        PII t = query(u << 1|1, l, r);
        if(t.first >= res) {
            res = t.first;
            resid = t.second;
        }
    }
    return {res, resid};
}

struct dx{
    int x, y, w;
}ww[N];

int pre[N];

void solve()
{
    int H, W, n;
    cin >> H >> W >> n;
    for(int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        ww[i] = {x, y, i};
    }
    build(1, 1, W);
    ww[++n] = {1,1,0};
    ww[++n] = {H,W,0};

    sort(ww + 1, ww + n + 1, [&](dx a, dx b){
        if(a.x != b.x) return a.x > b.x;
        return a.y > b.y;
    });


    for(int i = 1; i <= n; i ++) {
        if(i != 1) {
            PII t = query(1, ww[i].y, W);
            // t.first += ww[i].w;
            // pre[i] = t.second;
            modify(1, ww[i].y, t.first, i);
            // if(i == n) {
            //     cout << t.first << endl;
            // }
        }
        else {
            modify(1,ww[i].y, ww[i].w ,i);
        }
    }

    cout << "S" << endl;
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