zize;
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
cout << tr[u].key << " ";
inorder(tr[u].rson);
}
}


void solve() {

int q;
cin >> q;
while(q --) {
int opt, x;
cin >> opt >> x;
switch (opt)
{
    case 1: // 插入x
        fhq::insert( x); 
        break;
    case 2: // 删除x
        fhq::Del(x); 
        break;
    case 3: // 查询x的排名
        cout << fhq::Rank(x) << endl; 
        break;
    case 4: // 查询第x小
        cout << fhq::kth(fhq::root, x) << endl; 
        break;
    case 5: // 查询x的前驱（小于x的最大数）
        cout << fhq::Precursor(x) << endl; 
        break;
    case 6: // 查询x的后继（大于x的最小数）
        std::cout << fhq::Successor(x) << endl; 
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
z