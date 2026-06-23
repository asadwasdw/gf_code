#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int n,m;
int a[N];


struct gfdzxs
{
    struct Node{
        int l, r;
        int cnt;
        int sum;
    }tr[N<<5];

    int root[N], idx;
    vector<int>nums;
    int find(int x) {
        return lower_bound(nums.begin(),nums.end(),x) - nums.begin();
    }

    void pushup(int q) {
        tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
        tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;
    }

    int insert(int p, int l, int r, int x) {
        int q = ++ idx;
        tr[q] = tr[p];
        if(l == r) {
            tr[q].cnt ++ ;
            tr[q].sum += nums[x];

            return q;
        }
        int mid = l + r >> 1;
        if(x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
        else tr[q].r = insert(tr[p].r, mid + 1, r, x);
        pushup(q);
        return q;
    }

    int query(int p, int q, int l, int r, int k) { //求区间lr第k小数
        
        if(l == r) return r;
        int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
        int mid = l + r >> 1;
        if(k <= cnt) return query(tr[p].l, tr[q].l, l, mid, k);
        return query(tr[p].r, tr[q].r, mid + 1, r, k - cnt);
    }

    int querymaxKsum(int p, int q, int l, int r, int k) {
        k = min(k, tr[q].cnt - tr[p].cnt);
        
        if(l == r) {
            int sum = tr[q].sum - tr[p].sum;
            int cnt = tr[q].cnt - tr[p].cnt;
            if(!cnt) return 0;
            return sum / cnt * k;
        }

        int cnt = tr[tr[q].r].cnt - tr[tr[p].r].cnt; // 右边数的个数
        int mid = l + r >> 1;
        if(k <= cnt) return querymaxKsum(tr[p].r, tr[q].r, mid + 1, r, k);
        return tr[tr[q].r].sum - tr[tr[p].r].sum + querymaxKsum(tr[p].l, tr[q].l, l, mid, k - cnt);
    }

    int Querymink(int l,int r,int k) {
        return nums[query(root[l - 1], root[r], 0, nums.size() - 1, k)];
    }
    
    int QuerymaxKsum(int l,int r,int k) { // 求区间lr前k个最大数的和
        return querymaxKsum(root[l - 1], root[r], 0, nums.size() - 1, k);
    }

    void init() {
        for(int i = 1; i <= n; i ++)nums.push_back(a[i]);
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        for(int i = 1; i <= n; i ++) root[i] = insert(root[i - 1], 0, nums.size() - 1,find(a[i]));
    }
    
}zxs;


int ans[N];


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    zxs.init();




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}