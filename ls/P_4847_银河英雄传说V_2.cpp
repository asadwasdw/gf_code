#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define int long long


//vector<vector<int>>adj(N);


namespace fhq {
    int root = 0;
    int cnt = 0;
    struct Node {
        int lson, rson;
        int key, pri;
        int size;
        int val, sum;
        int fa;
    }tr[N];

    int new_node(int x) { // 新建一个节点 key为x 返回节点的编号
        cnt ++;
        tr[cnt].size = 1;
        tr[cnt].fa = tr[cnt].lson = tr[cnt].rson = 0; //  左右儿子为空

        tr[cnt].val = x;

        tr[cnt].sum = x;
        tr[cnt].pri = rand(); // 随机优先级
        return cnt;
    }

    void update(int u) { 
        tr[u].size = tr[tr[u].lson].size + tr[tr[u].rson].size + 1;
        tr[u].sum = tr[tr[u].lson].sum + tr[tr[u].rson].sum + tr[u].val;

        tr[tr[u].lson].fa = u;
        tr[tr[u].rson].fa = u;
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

    void split2(int u, int x, int &L, int &R) {
        if(u == 0) {
            L = R = 0;
            return;
        }
        if(tr[tr[u].lson].size + 1 <= x) {
            L = u;
            tr[tr[u].rson].fa = 0;
            split2(tr[u].rson, x - tr[tr[u].lson].size - 1, tr[u].rson, R);
        } else {
            R = u;
            tr[tr[u].lson].fa = 0;
            split2(tr[u].lson, x, L, tr[u].lson);
        }
        update(u);
    }

    int get_rank(int u) { // 查询在中序遍历中, 左边有多少个元素， 用来确定当前元素的位置
        int res = tr[tr[u].lson].size;

        while(tr[u].fa) {
            if(u == tr[tr[u].fa].rson) {
                res += tr[tr[tr[u].fa].lson].size + 1;
            }
            u = tr[u].fa;
        }


        return res;

    }

    int find(int u) {
        if(tr[u].fa == 0) return u;
        return find(tr[u].fa);
    }


    void inorder(int u) {
        if(u == 0) 
            return;

        inorder(tr[u].lson);
        cout << u << " ";
        inorder(tr[u].rson);
    }
}



void solve() {

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        fhq::new_node(x);
    }

    for(int i = 1; i <= k; i ++) {
        char op; cin >> op;
        if(op == 'M') {
            int x, y;
            cin >> x >> y;

            x = fhq::find(x);
            y = fhq::find(y);
            // cout << x << " " << y << endl;

            if(x == y) continue;
            fhq::merge(y, x);
        } else if(op == 'D') {
            int x; cin >> x;
            int root = fhq::find(x), L, R;
            // cout << root << endl;
            int res = fhq::get_rank(x);
            fhq::split2(root, res, L, R);
            // cout << x << " " << res << " " << L << " " << R << endl;

            // for(int i = 1; i <= n; i ++) {
            //     cout << fhq::tr[i].fa << " \n"[i == n];
            // }

            fhq::tr[L].fa = 0;
            fhq::tr[R].fa = 0;
        } else {
            int x, y;
            cin >> x >> y;
            int fx = fhq::find(x), fy = fhq::find(y);
            if(fx != fy) {
                cout << "-1" << endl;
            } else {
                int root = fx, L, R, p;
                int res1 = fhq::get_rank(x), res2 = fhq::get_rank(y);
                if(res1 > res2) swap(res1, res2);
                
                // cout << res1 << " " << res2 << endl;
                fhq::split2(root, res1, L, R);
                fhq::split2(R, res2 - res1 + 1, p, R);

                cout << fhq::tr[p].sum << endl;

                fhq::merge(fhq::merge(L, p), R);
            }
        }
        
        // cout << i << ":" << endl;
        // cout << "中序遍历"  << endl;
        // for(int u = 1; u <= n; u ++) {
        //     if(u == fhq::tr[u].fa) {
        //         cout << u << " : ";
        //         fhq::inorder(u);
        //         cout << endl;
        //     }
        // }

        // cout << "树结构" << endl;

        // for(int u = 1; u <= n; u ++) {
        //     if(fhq::tr[u].lson) cout << u << " " << fhq::tr[u].lson << endl;
        //     if(fhq::tr[u].rson) cout << u << " " << fhq::tr[u].rson << endl;
        // }

    
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