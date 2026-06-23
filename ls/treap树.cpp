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

//vector<vector<int>>adj(N);

int cnt = 0;
struct Node {
    int lson, rson;
    int key, pri;
    int size;
}tr[N];

int new_node(int x) {
    cnt ++;
    tr[cnt].size = 1;
    tr[cnt].lson = tr[cnt].rson = 0;
    tr[cnt].key = x;
    tr[cnt].pri = rand(); // 随机优先级
    return cnt;
}

void update(int u) {
    tr[u].size = tr[tr[u].lson].size + tr[tr[u].rson].size + 1;
}

void rotate(int &root, int d) { // d = 0 右旋， = 1 左旋
    int k;
    if(d == 1) { // 把root和右儿子交换位置， 为了保证中序遍历不变， 右儿子的左儿子也要变成root的右儿子 
        k = tr[root].rson;
        tr[root].rson = tr[k].lson;
        tr[k].lson = root;
    } else {
        k = tr[root].lson;
        tr[root].lson = tr[k].rson;
        tr[k].rson = root;
    }
    update(root); 
    update(k);
    root = k;
}

void insert(int &u,int x) {
    if(u == 0) {
        u = new_node(x);
        return;
    }
    tr[u].size ++;
    if(x >= tr[u].key) {
        insert(tr[u].rson, x);
    } else {
        insert(tr[u].lson, x);
    }

    if(tr[u].lson != 0 && tr[u].pri > tr[tr[u].lson].pri) rotate(u, 0); // 小的放上面
    if(tr[u].rson != 0 && tr[u].pri > tr[tr[u].rson].pri) rotate(u, 1);
    update(u);
}

void Del(int &u, int x) {
    if(u == 0) return; // 空节点，直接返回（避免访问tr[0].size）
    tr[u].size --;
    if(tr[u].key == x) { // 找到要删除的节点
        // 情况1：叶子节点
        if(tr[u].lson == 0 && tr[u].rson == 0) {
            u = 0;
            return;
        }
        // 情况2：只有一个子节点
        if(tr[u].lson == 0 || tr[u].rson == 0) {
            u = tr[u].lson + tr[u].rson; // 直接替换为非空子节点
            return;
        }
        // 情况3：有两个子节点 → 旋转到叶子再删
        if(tr[tr[u].lson].pri < tr[tr[u].rson].pri) {
            rotate(u, 0); // 右旋：左儿子上旋，目标节点到右子树
            Del(tr[u].rson, x);
        } else {
            rotate(u, 1); // 左旋：右儿子上旋，目标节点到左子树
            Del(tr[u].lson, x);
        }
    } else if(x < tr[u].key) { // 去左子树删
        Del(tr[u].lson, x);
    } else { // 去右子树删
        Del(tr[u].rson, x);
    }
    update(u); // 回溯更新size（确保子树大小正确）
}


// 返回：严格小于x的节点数量（排名=返回值+1）
int Rank(int u, int x) {
    if(u == 0) return 0; // 空节点，无小于x的数
    if(x > tr[u].key) {
        // x比当前节点大 → 左子树全算 + 当前节点 + 右子树中小于x的数
        return tr[tr[u].lson].size + 1 + Rank(tr[u].rson, x);
    } else {
        // x≤当前节点 → 只查左子树
        return Rank(tr[u].lson, x); // 原代码错误写为tr[u].rson
    }
}

int kth(int u, int k) {
    int mid = tr[tr[u].lson].size + 1;
    if(k == mid) return tr[u].key;
    if(k > mid) return kth(tr[u].rson, k - mid);
    if(k < mid) return kth(tr[u].lson, k);
}

int Precursor(int u, int x) {
    if(u == 0) return 0;
    if(tr[u].key >= x) return Precursor(tr[u].lson, x); // 左边比他小
    int tmp = Precursor(tr[u].rson, x); // 去右边找一个比x小的
    if(tmp == 0) return tr[u].key; // 没找到， 只能是当前的了
    return tmp; 
}

int Successor(int u, int x) {
    if(u == 0) return 0;
    if(tr[u].key <= x) return Successor(tr[u].rson, x);
    int tmp = Successor(tr[u].lson, x); 
    if(tmp == 0) return tr[u].key; // 没找到， 只能是当前的了
    return tmp; 
}

void solve() {
    int root = 0;
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
                Del(root, x); 
                break;
            case 3: // 查询x的排名（+1是因为排名从1开始）
                cout << Rank(root, x) + 1 << endl; 
                break;
            case 4: // 查询第x小
                cout << kth(root, x) << endl; 
                break;
            case 5: // 查询x的前驱（小于x的最大数）
                cout << Precursor(root, x) << endl; 
                break;
            case 6: // 查询x的后继（大于x的最小数）
                cout << Successor(root, x) << endl; 
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