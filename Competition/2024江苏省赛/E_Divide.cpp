#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);        
int n,m;
int a[N];       
#define ls k << 1
#define rs k << 1 | 1
struct node
{
    int val[20];
    node(){
        for(int i=0; i<20; ++i)val[i] = 0;
    }
}tr[N << 2];

void pushup(node &k, node &ll, node &rr){
    for(int i=0; i<20; ++i){
        k.val[i] = ll.val[i] + rr.val[i];
    }
}
void build(int k, int l, int r){
    if(l == r){
        if(a[l] != 0){
            int p = __lg(a[l]);
            tr[k].val[p]++;  
        }
        
        return;
    }
    int mid = l + r>> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    pushup(tr[k], tr[ls], tr[rs]);
}

node query(int k, int l, int r, int ql, int qr){
    if(l == ql && r == qr){
        return tr[k];
    }
    int mid = l + r >> 1;
    if(mid >= qr)return query(ls, l, mid, ql, qr);
    else if(mid < ql)return query(rs, mid+1, r, ql, qr);
    node res, ll = query(ls, l, mid, ql, mid), rr = query(rs, mid+1, r, mid+1, qr);
    pushup(res, ll, rr);
    return res;
}   

int root[20][N], idx;
struct gf   
{
    int l, r, val;
}tree[N * 25 * 20];

void update(int pre, int &k, int l, int r, int x){
    k = ++idx;
    tree[k] = tree[pre];
    tree[k].val++;
    if(l == r)return;
    int mid = l + r >> 1;
    if(mid >= x)update(tree[pre].l, tree[k].l, l, mid, x);
    else update(tree[pre].r, tree[k].r, mid+1, r, x);
}

int query2(int pre, int k, int l, int r, int x){
    if(l == r)return l;
    int mid = l + r >> 1;
    int val = tree[tree[k].r].val - tree[tree[pre].r].val;
    if(val >= x)return query2(tree[pre].r, tree[k].r, mid+1, r, x);
    return query2(tree[pre].l, tree[k].l, l, mid, x - val);
}


void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        int x = a[i];
        for(int j=0; j<20; ++j)root[j][i] = root[j][i-1];
        while(x){
            int p = __lg(x);
            // cerr << x << ' ';
            update(root[p][i-1], root[p][i], (1<<p), (1<<p+1), x);
            x /= 2;
        }
    }
    // cout << query2(root[3][0], root[3][1], 1<<3, 1<<3+1, 2) << endl;
    build(1, 1, n);
    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        auto res = query(1, 1, n, l, r);
        bool f = false;
        for(int i=20-1; i>0; --i){
            if(res.val[i] == 0)continue;
            if(res.val[i] > k){
                f = true;
                cout << query2(root[i][l-1], root[i][r], (1<<i), (1<<i+1), k+1) << endl;
                break;
            }
            else{
                k -= res.val[i];
                res.val[i-1] += res.val[i];
            }
        }
        if(f)continue;
        if(res.val[0] > k){
            cout << query2(root[0][l-1], root[0][r], (1<<0), (1<<0+1), k+1) << endl;
            continue;
        }
        cout << 0 << endl;
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