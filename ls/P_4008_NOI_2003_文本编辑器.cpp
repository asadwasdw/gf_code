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
    }tr[N];

    int new_node(int x) { // 新建一个节点 key为x 返回节点的编号
        cnt ++;
        tr[cnt].size = 1;
        // tr[cnt].lson = tr[cnt].rson = 0; //  左右儿子为空
        tr[cnt].key = x;
        tr[cnt].pri = rand(); // 随机优先级
        return cnt;
    }

    void update(int u) { 
        tr[u].size = tr[tr[u].lson].size + tr[tr[u].rson].size + 1;
    }

    void split(int u, int x, int &L, int &R) {
        if(u == 0) {
            L = R = 0;
            return;
        }
        if(tr[u].key <= x) {
            L = u;
            split(tr[u].rson, x, tr[u].rson, R);
        } else {
            R = u;
            split(tr[u].lson, x, L, tr[u].lson);
        }
        update(u);
    }

    int merge(int L, int R) {
        if(L == 0 || R == 0) return L + R;
        if(tr[L].pri > tr[R].pri) {
            tr[L].rson = merge(tr[L].rson, R);
            update(L);
            return L;
        } else {
            tr[R].lson = merge(L, tr[R].lson);
            update(R);
            return R;
        }
    }


    void insert(int x) {
        int L, R;
        split(root, x, L, R);
        int p = new_node(x);
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
        
        inorder(tr[u].lson);
        cout << (char)tr[u].key;
        inorder(tr[u].rson);
    }
}


void solve() {
    

    int q;
    cin >> q;
    int pos = 0;
    for(int i = 1; i <= q; i ++) {
        string op;
        cin >> op;
        int L, R, p ;
        if(op == "Move") {
            int k;
            cin >> k;
            pos = k;
        } else if(op == "Insert") {
            fhq::split2(fhq::root, pos, L, R);
            int n;
            char t;
            cin >> n;
            for(int j = 1; j <= n; j ++) {
                t = getchar();
                while(t < 32 || t > 126) t = getchar();
                L = fhq::merge(L, fhq::new_node((int)t));
            }

            fhq::root = fhq::merge(L, R);
        } else if(op == "Delete") {
            
            fhq::split2(fhq::root, pos, L, R);

            int n; cin >> n;
            fhq::split2(R, n, p, R);

            fhq::root = fhq::merge(L, R);
        } else if(op == "Get") {
            int n; cin >> n;
            fhq::split2(fhq::root, pos, L, R);
            fhq::split2(R, n, p, R);

            fhq::inorder(p);
            cout << endl;

            fhq::root = fhq::merge(fhq::merge(L, p), R);
        } else if(op == "Prev") {
            pos --;
        } else if(op == "Next") {
            pos ++;
        }
        cout << i <<  " ";
        fhq::inorder(fhq::root);
        cout << endl;
    }
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