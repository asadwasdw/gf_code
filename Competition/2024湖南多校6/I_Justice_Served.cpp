#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define ls k<<1
#define rs k<<1|1

//vector<vector<int>>edg(N);
int n,m;
array<int, 3> a[N];


struct node{
    int l,r;
    int val;
}tr[N << 2];

void build(int k, int l, int r){
    tr[k] = {l, r, 0};
    if(l == r)return;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
}

void update(int k, int x, int d){
    if(tr[k].l == x && tr[k].r == x){
        tr[k].val = max(tr[k].val, d);
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= x)update(ls, x, d);
    else update(rs, x, d);
    tr[k].val = max(tr[ls].val, tr[rs].val);
}
int query(int k, int ql, int qr){
    if(ql <= tr[k].l && qr >= tr[k].r){
        return tr[k].val;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    int res = 0;
    if(mid >= ql)res = max(res, query(ls, ql, qr));
    if(mid < qr)res = max(res, query(rs, ql, qr));
    return res;
}

void solve()
{
    cin >> n;
    vector<int> p;
    for(int i=1; i<=n; ++i){
        cin >> a[i][0] >> a[i][1], a[i][2] = i, a[i][1] += a[i][0];
        p.push_back(a[i][0]);
        p.push_back(a[i][1]);
    }
    sort(a+1, a+1+n, [&](array<int, 3> a, array<int, 3> b){
        if(a[0] == b[0])return a[1] > b[1];
        return a[0] < b[0];
    });
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    build(1, 1, p.size());
    auto get = [&](int x){
        return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    vector<int> res(n+1);
    int root = 0;
    for(int i=1; i<=n; ++i){
        auto [l, r, id] = a[i];
        l = get(l);
        r = get(r);
        
        res[id] = query(1, r, p.size());
        // cout << id << ' ' << res[id] << ' ' << l << ' ' << r << endl;
        update(1, r, res[id]+1);
    }
    for(int i=1; i<=n; ++i)cout << res[i] << " \n"[i == n];






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