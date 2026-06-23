#include<bits/stdc++.h>
#define MAXN 1010
#define lson now << 1
#define rson now << 1 | 1
using namespace std;
typedef long long ll;
// 内层线段树节点，维护纵坐标
struct node_y{
    int l, r;
    ll res;
};
// 内层线段树
struct tree_y{
    node_y tree[MAXN << 2];
    void push_up(int now){ tree[now].res = tree[lson].res + tree[rson].res; };
    void build(int now, int l, int r){
        tree[now].l = l; tree[now].r = r;
        if(l == r) return ;
        int mid = (l + r) >> 1;
        build(lson, l, mid); build(rson, mid + 1, r);
        push_up(now);
    }
    /*
        实际上，内层线段树的修改与查询有两种写法，这是其中一种，也是我们通常情况下使用的。
        另一种称为“标记永久化”，在后面会有提到。
    */
    void update(int now, int y, int k){
        if(tree[now].l == tree[now].r){
            tree[now].res += k;
            return ;
        }
        int mid = (tree[now].l + tree[now].r) >> 1;
        if(y <= mid) update(lson, y, k);
        else update(rson, y, k);
        push_up(now);
    }
    ll query(int now, int l, int r){
        if(tree[now].l >= l && tree[now].r <= r) return tree[now].res;  
        int mid = (tree[now].l + tree[now].r) >> 1;
        if(r <= mid) return query(lson, l, r);
        else if(l > mid) return query(rson, l, r);
        else return query(lson, l, mid) + query(rson, mid + 1, r);
    }
};
// 外层线段树节点，维护横坐标
struct node_x{
    int l, r;
    tree_y tr;
};
// 外层线段树

struct node_x{
    int l, r;
    /*
        这里依旧有懒惰标记的存在，只是我们不会下传，而是经过它是加上它的影响。
        懒惰标记不再是普通线段树的 int 或者 long long 之类的类型，它同样是一棵线段树，因为不是所有的纵向区间的懒惰标记都是一样的
    */
    tree_y lazy_tag;
    tree_y tr; // 对应的内层线段树
};
/*
    外层线段树的结构体
    同样作为一个结构体来处理
*/
struct tree_x{
    int m; // 表示纵向总长度，便于内层建树
    node_x tree[MAXN << 2];
    void build(int now, int l, int r){
        tree[now].l = l; tree[now].r = r;
        tree[now].tr.build(1, 1, m); tree[now].lazy_tag.build(1, 1, m); // 别忘了在这里对内层线段树建树，每个结点都要，而不是仅仅叶子结点
        if(tree[now].l == tree[now].r) return ;
        int mid = (l + r) >> 1;
        build(lson, l, mid); build(rson, mid + 1, r);
    }
    void update(int now, int l1, int r1, int l2, int r2, int val){
        /*
            相信很多人都不理解为什么这里也要对内层修改，这样不是相当于扩大了范围吗？
            仔细思考会发现，不修改是绝对不行的，因为当前所覆盖的范围肯定包括了我们要修改的矩形，也就是说，当前结点的答案是有可能由修改的那个矩形中更新过来的
            而如果我们仅仅在当前覆盖的范围等于我们要修改的矩形的范围是修改，那么在更大范围的查询时就会出问题
            比如当前的横向区间是 [1,4]，最大值为 1，而我们修改的矩形的左上角和右下角分别是 (2,2) 和 (3,3)，修改后的值为 5
            如果没有这里的修改，再查询左上角和右下角分别是 (1,1) 和 (4,4) 的矩形的时候，我们得到的答案将会是 1
            可是修改貌似也不对。在一般情况下确实是错误的，这样的要求也造就了树套树写法的局限性
            对于矩阵推平 + 矩阵最大值的题目，我们只有在保证矩阵推平所赋的值不小于推平前的矩阵最大值的时候才保证树套树写法的正确性，求最小值同理。
            至于为什么这种情况下是对的，显然，当前所覆盖的范围肯定包括了我们要修改的矩形
            既然这个矩形被赋的值会大于当前区域的最大值，那么当前覆盖的范围的最大值一定来自那个矩形
            可以自己举例理解一下
        */
        tree[now].tr.update(1, l2, r2, val);
        if(tree[now].l >= l1 && tree[now].r <= r1){
            // 懒惰标记的修改就只需要在这里修改了
            tree[now].lazy_tag.update(1, l2, r2, val);
            return ;
        }
        int mid = (tree[now].l + tree[now].r) >> 1;
        if(r1 <= mid) update(lson, l1, r1, l2, r2, val);
        else if(l1 > mid) update(rson, l1, r1, l2, r2, val);
        else update(lson, l1, mid, l2, r2, val), update(rson, mid + 1, r1, l2, r2, val);
    }
    ll query(int now, int l1, int r1, int l2, int r2){
        if(tree[now].l >= l1 && tree[now].r <= r1) return tree[now].tr.query(1, l2, r2);
        int mid = (tree[now].l + tree[now].r) >> 1;
        // 懒惰标记在这里用上，记录是沿途经过的点的懒惰标记的影响
        ll res = tree[now].lazy_tag.query(1, l2, r2);
        if(r1 <= mid) return max(res, query(lson, l1, r1, l2, r2));
        else if(l1 > mid) return max(res, query(rson, l1, r1, l2, r2));
        else return max(res, max(query(lson, l1, mid, l2, r2), query(rson, mid + 1, r1, l2, r2)));
    }
};
tree_x tree;
int n, m, q;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    tree.m = m; tree.build(1, 1, n);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op == 1){
            int x, y, k;
            scanf("%d%d%d",&x,&y,&k);
            tree.update(1, x, y, k);
        }else{
            int x1, y1, x2, y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("%lld\n",tree.query(1, x1, x2, y1, y2));
        }
    }
}
