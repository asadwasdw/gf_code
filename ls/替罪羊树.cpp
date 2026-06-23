
// 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first 
#define y second

const double alpha = 0.75;

//vector<vector<int>>adj(N);

struct Node {
    int lson, rson;
    int val; // 存的值
    int tot; // 所用空间大小， 有两类点 目前存在的点和被删除的点，可看后面删除操作。
    int size; // 子树实际存储的节点数量
    int del; // 1表示未被删除， 为0表示删除了
}tr[N];

int order[N], cnt; // 用来记录中序遍历的结果， 也就是维护的信息
int root; // 根， 单独保存是因为重建的操作可能会改变根节点
stack<int>tree_stack ; // 用栈记录被回收的空间，可以再次利用一下，笔者喜欢stl

void inorder(int u) { // 中序遍历，排平操作，获取这个子树到达存了什么信息
    if(!u) return;
    inorder(tr[u].lson);
    if(tr[u].del) order[++cnt] = u;  // 存在的点， 记录一下
    else tree_stack.push(u);     // 被删除的点， 那么也记录一下，准备重新分配空间
    inorder(tr[u].rson);
}

void init_node(int u) { // 初始化一个节点u, val 直接修改
    tr[u].lson = tr[u].rson = 0;
    tr[u].size = tr[u].tot = tr[u].del = 1;
}

void update(int u) { // 根据左右儿子信息更新u节点
    tr[u].size = tr[tr[u].lson].size + tr[tr[u].rson].size + tr[u].del;
    tr[u].tot = tr[tr[u].lson].tot + tr[tr[u].rson].tot + 1;
}

void build(int l, int r, int &u) { // 建树， 这颗树的根节点 就是 u

    if(l > r) {
        u = 0;
        return;
    }
    int mid = l + r >> 1;
    u = order[mid];

    if(l == r) {
        init_node(u);
        return;
    }

    build(l, mid - 1, tr[u].lson);
    build(mid + 1, r, tr[u].rson);
    update(u);
}

void rebuild(int &u) { // 重建树，根节点是u
    cnt = 0;
    inorder(u); // 先得到这个子树的信息，拍平一下，
    if(cnt) build(1, cnt, u); // 把这个消息重建在 节点u
    else u = 0;
}

bool not_balance(int u) {
    int max_child = max(tr[tr[u].lson].size, tr[tr[u].rson].size);
    // 正确条件：任意子树有效数 > 当前节点有效数 * alpha
    return 1.0 * max_child > 1.0 * tr[u].size * alpha;
}

void insert(int &u, int x) { // 给子树u， 插入一个数字x
    if (u == 0) {
        u = tree_stack.top(); tree_stack.pop();
        tr[u].val = x;
        init_node(u);
        return;
    }
    // 放到子树里面
    tr[u].size ++;
    tr[u].tot ++;
    if(x < tr[u].val )insert(tr[u].lson, x); // 小于放左边， 取等号也不会影响
    else insert(tr[u].rson, x);
    if(not_balance(u)) rebuild(u); 
}

int Rank(int u, int x) { // 查x是第几名 哪个地方有个rank？ 防止重名
    if(u == 0) {
        return 0;
    }

    if(x > tr[u].val) {
        return tr[tr[u].lson].size + tr[u].del + Rank(tr[u].rson, x); // 左边 + 当前 + 右边第几
    }

    return Rank(tr[u].lson, x);
}

int kth(int k) {
    int u = root;
    while(u) {
        int left_size = tr[tr[u].lson].size;
        // 找到目标有效节点
        if(tr[u].del && left_size + 1 == k) {
            return tr[u].val;
        } else if(left_size >= k) {
            // 第k小在左子树
            u = tr[u].lson;
        } else {
            // 第k小在右子树，减去左子树和自身的有效数
            k -= left_size + tr[u].del;
            u = tr[u].rson;
        }
    }
    // 边界：k超出范围时返回非法值（避免访问空节点）
    return -INF;
}

void Del_k(int &u, int k) {
    if(!u) return; // 空节点直接返回
    int left_size = tr[tr[u].lson].size;

    // 找到目标节点，标记为删除
    if(tr[u].del && left_size + 1 == k) {
        tr[u].del = 0;
        update(u); // 更新当前节点
        return;
    }

    // 递归删除左/右子树
    if(left_size + tr[u].del >= k) {
        Del_k(tr[u].lson, k);
    } else {
        Del_k(tr[u].rson, k - left_size - tr[u].del);
    }

    update(u); // 回溯更新当前节点（关键）
}


void Del(int x) {
    int rk = Rank(root, x); // x的排名（小于x的数的个数）
    int total = tr[root].size; // 总有效节点数
    // 检查x是否存在（排名+1 <= 总有效数，且第rk+1小的数等于x）
    if(rk + 1 > total || kth(rk + 1) != x) {
        return; // x不存在，直接返回
    }
    Del_k(root, rk + 1); // 删除第rk+1小的数（即x）
    
    // 正确的重建条件：有效数/总空间 < alpha 时重建
    if(1.0 * tr[root].size < 1.0 * tr[root].tot * alpha) {
        rebuild(root);
    }
}





void solve() {
    // 初始化根节点和空间池
    root = 0;
    for(int i = 1; i < N; i ++) {
        tree_stack.push(i);
    }

    int q;
    cin >> q;
    while(q --) {
        int opt, x;
        cin >> opt >> x;
        switch (opt)
        {
            case 1: // 插入x
                insert(root, x); 
                break;
            case 2: // 删除x
                Del(x); 
                break;
            case 3: // 查询x的排名（+1是因为排名从1开始）
                cout << Rank(root, x) + 1 << endl; 
                break;
            case 4: // 查询第x小
                cout << kth(x) << endl; 
                break;
            case 5: // 查询x的前驱（小于x的最大数）
                cout << kth(Rank(root, x)) << endl; 
                break;
            case 6: // 查询x的后继（大于x的最小数）
                cout << kth(Rank(root, x + 1) + 1) << endl; 
                break;
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
    return 0;
}