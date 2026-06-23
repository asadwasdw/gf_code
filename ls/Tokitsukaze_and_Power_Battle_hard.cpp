#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


struct node{
    int l,r;
    int sum,rmx,lmn,lans,rans,segans,ans;
}tr[N<<2];
#define lson tr[u<<1]
#define rson tr[u<<1|1]
#define root tr[u]

node merge_node(node x, node y) {
    node res;
    res.l = x.l;
    res.r = y.r;
    res.sum = x.sum + y.sum;
    res.rmx = max(x.rmx + y.sum, y.rmx);
    res.lmn = min(x.lmn, x.sum + y.lmn);
    res.lans = max({x.lans, x.sum - y.lmn, x.sum + y.lans,x.segans-y.lmn});
    //(减号的位置)
    // 包括左端点的最大答案，{左边全部-右边左端点最小（中），左边全部+右边左端点答案（右），左边全部答案-右边左端点最小（左）}
    res.rans = max({y.rans, x.rans - y.sum, x.rmx - y.sum, x.rmx + y.segans});
    // 包括右端点的最大答案，{左边右端点答案-右边全部（左），左边右端点最大-右边全部（中），左边右端点最大-右边全部答案（右）}
    res.segans = max({x.segans - y.sum , x.sum + y.segans, x.sum - y.sum});
    // 包括左右全端点的最大答案，{左边全答案-右边全部（左），左边全部+右边全答案（右），左边全部-右边全部（中）}
    res.ans = max({x.ans, y.ans, x.rmx+y.lans, x.rmx - y.lmn, x.rans - y.lmn});
     // 包括最大答案，{左边右端点最大-右边左答案（右），左边右端点最大+右边左端点最小（中），左边右端点答案-右边左端点最小（左）}
    return res;
}

void pushup(int u){
    root = merge_node(lson,rson);
    return; 
}

int a[N];

void build(int u,int l,int r) {
    if(l == r) {
        root = {l,r,a[l],a[l],a[l],-INF,-INF,-INF,-INF};
        return;
    }
    tr[u] = {l,r};
   
    int mid = l+r>>1;
    build(u<<1, l, mid);
    build(u<<1|1, mid + 1, r);
    pushup(u);
    // cout<<root.l<<" "<<root.r<<" "<<root.ans<<endl;
}

void modify(int u,int x,int y) {
    // cout << root.l << " " << root.r <<endl;
    if(tr[u].l == tr[u].r && tr[u].l == x) {
        a[x] = y;
        root = {x, x, a[x] ,a[x] ,a[x],-INF, -INF, -INF, -INF};
        return ;
    }
    int mid = root.l + root.r >> 1;
    if(x <= mid) modify(u<<1, x, y);
    if(x >= mid + 1) modify(u<<1|1, x, y);
    pushup(u);
}

node query(int u, int l, int r) {
    // cout<<root.l<<" "<<root.r<<" "<<l<<" " <<r<<endl;

    if(l <= root.l && root.r <= r) {
        return root;
    }
    int mid = root.l + root.r >> 1;

    if(r <= mid) return query(u<<1, l, r);
    if(l >= mid + 1) return query(u << 1|1, l, r);
    return merge_node(query(u<<1, l, r),query(u<<1|1, l, r));
}

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while(k--) {
        int op,x,y;
        cin >> op >> x >> y;
        if(op == 1) {
            modify(1,x,y);
        }
        else cout<<query(1,x,y).ans<<endl;
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