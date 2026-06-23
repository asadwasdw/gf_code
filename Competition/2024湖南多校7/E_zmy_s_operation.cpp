#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
//#define endl "\n" 

//vector<vector<int>>edg(N);
int n, q;
int l, r, mid;
int a[N];
map<int,int> lv, rv;

int ask(int a,int b) {
    cout << "? "  << a << " " << b << endl;
    int t; cin >> t;
    return t;
}

void ok() {
    cout << "!" << endl;
}

void build() {
    mid = l + r >> 1;
//    cout << l << " " << r << " " << mid << endl;  
    lv.clear(), rv.clear();
    lv[mid] = a[mid];
    rv[mid + 1] = a[mid + 1];

    for(int i = mid - 1; i >= l; i --) {
        lv[i] = ask(a[i], lv[i + 1]);
    }

    for(int i = mid + 2; i <= r; i ++) {
        rv[i] = ask(a[i], rv[i - 1]);
    }
    ok();
}

void del(int u) {
    if(u == 0) {
        l ++;
        if(l > mid) build();
        else ok();
    }
    else {
        r --;
        if(r <= mid) build();
        else ok();
    }
}

void add(int u, int x) {
    if(u == 0) {
        l --;
        a[l] = x;
        if(l >= r) ok();
        else if(l == r - 1)  build();
        else lv[l] = ask(x, lv[l + 1]),ok();
    }
    else {
        r ++;
        a[r] = x;
        if(l >= r) ok();
        else if(l == r - 1) build();
        else rv[r] = ask(x, rv[r - 1]),ok();
    }
}


int query() {
    if(l == r) {
    	ok();
        return a[l];
    }
    int t = ask(lv[l],rv[r]);
    ok();
    return t;
}

void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i + q];
    }
    l = q + 1, r = q + n;
    if(n >= 2) build();
    else ok();

    while(q --) {
        int op, u, x;
        cin >> op;
        if(op == 1) {
            cin >> u >> x;
            add(u, x);
        }
        else if(op == 2) {
            cin >> u;
            del(u);
        }
        else cout << query() << endl;
//      for(int i = l; i <= r; i ++) cout << a[i] << " "; cout << endl;
    }
}


signed main()
{
    int t;t=1;
    for(int i=1;i<=t;i++){
        solve();
    }
}
