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
#define int long long
namespace fhq {
    int root = 0;
    int cnt = 0;
    struct Node {
        int lson, rson;
        int key, pri;
        int size;
        int val, max;
        int lazy, add;
    }tr[N];

    int new_node(int x) { // 新建一个节点 key为x 返回节点的编号
        cnt ++;
        tr[cnt].size = 1;
        tr[cnt].lson = tr[cnt].rson = 0; //  左右儿子为空
        tr[cnt].val = x;
        tr[cnt].max = x;
        tr[cnt].lazy = 0;
        tr[cnt].add = 0;
        tr[cnt].pri = rand(); // 随机优先级
        return cnt;
    }

    void update(int u) { 
        tr[u].size = tr[tr[u].lson].size + tr[tr[u].rson].size + 1;
        tr[u].max = tr[u].val;
        if(tr[u].lson) tr[u].max = max(tr[u].max, tr[tr[u].lson].max);
        if(tr[u].rson) tr[u].max = max(tr[u].max, tr[tr[u].rson].max);
    }

    void pushdown(int u) {
        if(tr[u].lazy) {
            swap(tr[u].lson, tr[u].rson);
            tr[tr[u].lson].lazy ^= 1;
            tr[tr[u].rson].lazy ^= 1;
            tr[u].lazy = 0;
        }

        if(tr[u].add) {
            
            tr[tr[u].lson].val += tr[u].add;
            tr[tr[u].lson].add += tr[u].add;
            tr[tr[u].lson].max += tr[u].add;

            tr[tr[u].rson].val += tr[u].add;
            tr[tr[u].rson].add += tr[u].add;
            tr[tr[u].rson].max += tr[u].add;

            tr[u].add = 0;
        }
        update(u);
    }


    int merge(int L, int R) {
        if(L == 0 || R == 0) return L + R;
        if(tr[L].pri > tr[R].pri) {
            pushdown(L);
            tr[L].rson = merge(tr[L].rson, R);
            update(L);
            return L;
        } else {
            pushdown(R);
            tr[R].lson = merge(L, tr[R].lson);
            update(R);
            return R;
        }
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
        fhq::root = fhq::merge(fhq::root, fhq::new_node(0)); 
    }

    for(int i = 1;  i <= m; i ++) {
        int k, l, r, v;
        cin >> k >> l >> r;

        int L, R, p;
        fhq::split2(fhq::root, l - 1, L, R);
        fhq::split2(R, r - l + 1, p, R);
        if(k == 1) {
            cin >> v;
            fhq::tr[p].val += v;
            fhq::tr[p].add += v;
        } else if(k == 2) {
            fhq::tr[p].lazy ^= 1;
        } else {
            cout << fhq::tr[p].max << endl;
        }

        // cout << L << " " << p << " " << R << endl;

        fhq::root = fhq::merge(fhq::merge(L, p), R);

        // fhq::inorder(fhq::root);
        // cout << endl;
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