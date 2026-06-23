
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


struct Node{
    int l,r;
    double sum;
    double add,mul;
}tr[N * 4];
double a[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void eval(Node &root, Node &lson, Node &rson) {
    lson.sum = lson.sum * root.mul + root.add * (lson.r - lson.l + 1);
    rson.sum = rson.sum * root.mul + root.add * (rson.r - rson.l + 1);

    lson.mul *= root.mul;
    rson.mul *= root.mul;

    lson.add = lson.add*root.mul + root.add;
    rson.add = rson.add*root.mul + root.add;

    root.add = 0;
    root.mul = 1;
}

void pushdown(int u) {
    eval(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if(l == r) {
        tr[u]={l,r,a[l],0,1};
        return;
    }
    tr[u] = {l,r,0,0,1};

    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1|1, mid + 1, r);
    pushup(u);
}

double query(int u,int x) {
    if(tr[u].l == tr[u].r){
        return tr[u].sum;
    }
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid)return query(u<<1,x);
    return query(u<<1|1,x);
}


double query(int u,int l,int r) {
    if( l <= tr[u].l && tr[u].r <= r){
        return tr[u].sum;
    }
    
    pushdown(u);
    double res = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)res += query(u<<1,l,r);
    if(r >= mid + 1) res += query(u<<1|1,l,r);
    return res;
}

void modify(int u,int l, int r, double add, double mul) {
    if(l <= tr[u].l &&  tr[u].r <= r) {
        tr[u].sum=tr[u].sum * mul + (tr[u].r - tr[u].l + 1) * add;
        tr[u].mul *= mul;
        tr[u].add = mul * tr[u].add + add;
        return ;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if(l <= mid) modify(u<<1, l, r, add, mul);
    if(r >= mid + 1) modify(u<<1|1, l, r, add, mul);
    pushup(u);
}





void solve()
{
    int n,m;
    cin >> n >> m;
    
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);

    while(m--) {
        int l,r,x;
        cin>>l>>r>>x;
        double len = r - l + 1;
        if(r - l == 0) {
            modify(1,l,r,x,0);
        }
        else modify(1,l,r,x/len,(len-1)/(len));
    }

    for(int i=1;i<=n;i++) {
         cout <<query(1,i,i) <<" ";
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
} 