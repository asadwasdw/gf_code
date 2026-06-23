#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

// vector<vector<int>>edg(N);

struct Node{
    int l,r;
    int max,id;
}tr[N<<2];

Node merge_Node(Node lson, Node rson) {
    Node res;
    res = {lson.l, rson.r};
    if(lson.max >= rson.max) {
        res.max = lson.max;
        res.id = lson.id;
    }
    else {
        res.max = rson.max;
        res.id = rson.id;
    }
    return res;
}
int a[N];
int m;

void pushup(int u) {
    tr[u] = merge_Node(tr[u<<1], tr[u<<1|1]);
}

void build(int u,int l,int r) {
    if(l == r) {
        tr[u] = {l, r, 0, l};
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1|1, mid + 1, r);
    pushup(u);
}

void modify(int u,int x,int y) {
    if(tr[u].l == tr[u].r && tr[u].l == x) {
        tr[u].max += y;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid) modify(u<<1, x, y);
    else modify(u<<1|1, x, y);
    pushup(u);
}

int query(int u, int l, int r,int x) {
    if(l > r) return -1;
    if(x > tr[u].max) return -1;

    if(tr[u].l == tr[u].r) {
        return tr[u].l;
    }
    int mid = tr[u].l + tr[u].r >> 1;

    if(tr[u<<1].max >= x) return query(u<<1,l,r,x);
    return query(u<<1|1,l,r,x);
}


void solve()
{
    int n;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }

    int ans1 = 0, ans2 = 0;
    build(1,1,n);

    for(int i = 1;i <= n; i++) {
        int id = query(1,1,ans1,a[i]);

        if(id == -1)  {
            id = ++ans1;
            modify(1,id,m-a[i]);
        }
        else {
            modify(1,id,-a[i]);
        }
    }

    multiset<int>s;
    for(int i = 1;i <= n;i++) {
        if(s.size() == 0 || *prev(s.end()) < a[i]) {
            s.insert(m - a[i]);
            ans2++;
        }
        else {
            auto t = s.lower_bound(a[i]);
            int x = *t - a[i];
            s.erase(t);
            if(x) s.insert(x);
        }

    }

    cout << ans1 << " " << ans2 << endl;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}