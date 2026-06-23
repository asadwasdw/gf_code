#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
string s[3];
struct node
{
    int l,r;
    int sum;
    int val, val2;
    int lz;
}tr[N << 2];
#define ls k<<1
#define rs k<<1|1

void pushup(int k){
    tr[k].val = tr[ls].val + tr[rs].val;
    tr[k].val2 = tr[ls].val2 + tr[rs].val2;
}
void pushdown(int k, int d){
    tr[k].val = tr[k].val2 = 0;
    tr[k].sum = d;
    if(d == 0)tr[k].val = tr[k].r - tr[k].l + 1;
    if(d == 9)tr[k].val2 = tr[k].r - tr[k].l + 1;
    tr[k].lz = d;
}
void pushdown(int k){
    if(tr[k].lz != -1){
        pushdown(ls, tr[k].lz);
        pushdown(rs, tr[k].lz);
        tr[k].lz = -1;
    }
}
void build(int k, int l, int r){
    tr[k] = {l, r, 0, 0, 0, -1};
    if(l == r){
        tr[k].sum = a[l];
        if(a[l] == 0)++tr[k].val;
        if(a[l] == 9)++tr[k].val2;
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    pushup(k);
}

void update(int k, int l, int r, int d){
    if(tr[k].l >= l && tr[k].r <= r){
        pushdown(k, d);
        return;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= l)update(ls, l, r, d);
    if(mid < r)update(rs, l, r, d);
    pushup(k);
}

int queryval(int k, int x){
    if(tr[k].l == tr[k].r)return tr[k].sum;
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= x)return queryval(ls, x);
    else return queryval(rs, x);
}

int query(int k, int x){
    if(tr[k].l == tr[k].r){
        return tr[k].l;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= x)return query(ls, x);
    int rval = query(rs, x);
    if(rval == tr[rs].l){
        if(tr[ls].val == 0)return tr[rs].l;
        if(tr[ls].val == tr[ls].r - tr[ls].l + 1)return tr[ls].l;
        return query(ls, x);
    }
    return rval;
}

int query2(int k, int x){
    if(tr[k].l == tr[k].r){
        
        return tr[k].l;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= x)return query2(ls, x);
    int rval = query2(rs, x);
    if(rval == tr[rs].l){
        if(tr[ls].val2 == 0)return tr[rs].l;
        if(tr[ls].val2 == tr[ls].r - tr[ls].l + 1)return tr[ls].l;
        return query2(ls, x);
    }
    return rval;
}


void solve()
{
    cin >> n >> m;
    cin >> s[1] >> s[2];
    for(int i=n-1; i>=0; --i){
        a[i+1] += s[1][i] - '0' + s[2][i] - '0';
        a[i] += a[i+1] / 10;
        a[i+1] %= 10;
    }
    s[1] = " " + s[1];
    s[2] = " " + s[2];
    build(1, 1, n);
    cout << query(1, 4) << endl;
    // for(int i=1; i<=n; ++i)cerr << a[i] << ' ';
    while(m--){
        int r,c,x;
        cin >> r >> c >> x;
        if(x == s[r][c] - '0'){
            cout << queryval(1, c) << ' ' << 0 << endl;
            // for(int i=1; i<=n; ++i)cout << queryval(1, i) << ' ';cout << endl;
            continue;
        }
        int preval = (s[r][c] - '0' + s[r^1^2][c] - '0');
        int st = 0;
        if(queryval(1, c) != preval % 10)st = 1;
        if(st)++preval;
        int pre = preval >= 10;
        s[r][c] = '0' + x;
        int sufval = s[r][c] - '0' + s[r^1^2][c] - '0';
        if(st)++sufval;
        int suf = sufval >= 10;
        // cout << s[1] << '\n' << s[2] << endl;

        if(pre == suf){
            update(1, c, c, sufval % 10);
            cout << sufval % 10 << ' ' << 2 << endl;
            // for(int i=1; i<=n; ++i)cout << queryval(1, i) << ' ';cout << endl;
            continue;
        }
        if(pre && !suf){
            
            int l = 0;
            if(c == 1 || queryval(1, c-1) != 0)l = c;
            else l = query(1, c-1);
            // cout << tr[1].val << ' ' << tr[1].val2 << endl;
            int res = c - l;
            // cout << l << ' ';
            if(l != 1){
                ++res;
                int val = queryval(1, l-1);
                update(1, l-1, l-1, val-1);
            }
            if(l <= c-1)
            update(1, l, c-1, 9);
            update(1, c, c, sufval);
            // cout << l << ' ' << c+1 << ' ' << (s[r][c] - '0' + s[r^1^2][c] - '0' + st) << endl;
            // for(int i=1; i<=n; ++i)cout << queryval(1, i) << ' ';cout << endl;
            cout << sufval << ' ' << res+2 << endl;
        }
        else{
            int l;
            if(c == 1 || queryval(1, c-1) != 9)l = c;
            else l = query2(1, c-1);
            int res = c - l;
            if(l != 1){
                ++res;
                int val = queryval(1, l-1);
                update(1, l-1, l-1, val+1);
            }
            if(l <= c-1)
            update(1, l, c-1, 0);
            update(1, c, c, (sufval) % 10);
            cout << sufval % 10 << ' ' << res+2 << endl;
            // for(int i=1; i<=n; ++i)cout << queryval(1, i) << ' ';cout << endl;
        }



        
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