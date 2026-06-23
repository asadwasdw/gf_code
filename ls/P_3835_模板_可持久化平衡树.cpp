#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

namespace fhq {
    int root = 0;
    int cnt = 0;
    struct Node {
        int lson, rson;
        int key, pri;
        int size;
        int val;
        int lazy;
    }tr[N];

    int new_node(int x) { // 新建一个节点 key为x 返回节点的编号
        cnt ++;
        tr[cnt].size = 1;
        // tr[cnt].lson = tr[cnt].rson = 0; //  左右儿子为空
        tr[cnt].val = x;
        tr[cnt].lazy = 0;
        tr[cnt].pri = rand(); // 随机优先级
        return cnt;
    }

    int clone(int u) {
        tr[++ cnt] = tr[u];
        return cnt; 
    }

    void update(int u) { 
        tr[u].size = tr[tr[u].lson].size + tr[tr[u].rson].size + 1;
    }

    void pushdown(int u) {
        if(tr[u].lazy) {
            swap(tr[u].lson, tr[u].rson);
            tr[tr[u].lson].lazy ^= 1;
            tr[tr[u].rson].lazy ^= 1;
            tr[u].lazy = 0;
        }
    }

    void split(int u, int x, int &L, int &R) {
        if(u == 0) {
            L = R = 0;
            return;
        }
        pushdown(u);

        if(tr[u].key <= x) {
            L = clone(u);
            split(tr[u].rson, x, tr[L].rson, R);
        } else {
            R = clone(u);
            split(tr[u].lson, x, L, tr[R].lson);
        }
        update(u);
    }

    int merge(int L, int R) {
        if(L == 0 || R == 0) return L + R;
        if(tr[L].pri > tr[R].pri) {
            pushdown(L);
            L = clone(L);
            tr[L].rson = merge(tr[L].rson, R);
            update(L);
            return L;
        } else {
            pushdown(R);
            R = clone(R);
            tr[R].lson = merge(L, tr[R].lson);
            update(R);
            return R;
        }
    }


    void insert(int &u, int x) {
        int p = new_node(x);
        int L, R;
        if()


        split(root, x, L, R);
        root = merge(merge(L, p), R);
    }

    void Del(int x) {
        int L, R, p;
        split(root, x, L, R);
        split(L, x - 1, L, p);
        p = merge(tr[p].lson, tr[p].rson);

        root = merge(merge(L, p), R);
    }

    int Rank(int x) {
        int L, R;
        split(root, x - 1, L, R);
        int res = tr[L].size + 1;
        root = merge(L, R);
        return res;
    }

    int kth(int u, int k) {
        int mid = tr[tr[u].lson].size + 1;
        if(k == mid) return tr[u].key;
        if(k < mid) return kth(tr[u].lson, k);
        if(k > mid) return kth(tr[u].rson, k - mid);
    }

    int Precursor(int x) {
        int L, R;
        split(root, x - 1, L, R);
        int res = kth(L, tr[L].size);
        root = merge(L, R);
        return res;
    }

    int Successor(int x) {
        int L, R;
        split(root, x, L, R);
        int res = kth(R, 1);
        root = merge(L, R);
        return res;
    }

    void split2(int u, int x, int &L, int &R) {
        if(u == 0) {
            L = R = 0;
            return;
        }
        pushdown(u);
        if(tr[tr[u].lson].size + 1 <= x) {
            L = u;
            split2(tr[u].rson, x - tr[tr[u].lson].size - 1, tr[u].rson, R);
        } else {
            R = u;
            split2(tr[u].lson, x, L, tr[u].lson);
        }
        update(u);
    }


    void inorder(int u) {
        if(u == 0) 
            return;
        
        pushdown(u);
        inorder(tr[u].lson);
        cout << tr[u].val << " ";
        inorder(tr[u].rson);
    }


}


void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        fhq::root = fhq::merge(fhq::root, fhq::new_node(i)); 
    }

    for(int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        int L, p, R;
        fhq::split2(fhq::root, l - 1, L, R);
        fhq::split2(R, r - l + 1, p, R);
        fhq::tr[p].lazy ^= 1;
        fhq::root = fhq::merge(fhq::merge(L, p), R);
        // cout << L << " " << p << " " << R << " " << fhq::root << endl;
        // cout << i << " ";
        // fhq::inorder(fhq::root);
        // cout << endl;
    }

    fhq::inorder(fhq::root);
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}