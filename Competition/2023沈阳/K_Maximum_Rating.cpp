#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n,m;
int a[N];

int cnt;
struct node
{
    int l,r;
    ll val, cnt;
}tr[N * 40];

void update(int &k, int l, int r, int x, int d){
    if(!k)k = ++cnt;
    tr[k].cnt += d;
    tr[k].val += d * x;
    if(l == r)return;
    int mid = l + r >> 1;
    if(mid >= x)update(tr[k].l, l, mid, x, d);
    else update(tr[k].r, mid+1, r, x, d);
}

int query(int k, int l, int r, ll x){
    if(l == r){
        int temp = x / l;
        return min((ll)temp, tr[k].cnt);
    }
    int mid = l + r >> 1;
    if(x >= tr[tr[k].l].val){
        return tr[tr[k].l].cnt + query(tr[k].r, mid+1, r, x - tr[tr[k].l].val);
    }
    return query(tr[k].l, l, mid, x);
}


void solve()
{
    cin >> n >> m;
    tr[0] = {0, 0, 0, 0};
    int root = 0;
    ll fu = 0, fu_cnt = 0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i] > 0)
        update(root, 1, (int)1e9, a[i], 1);
        else fu -= a[i], ++fu_cnt;
    }
    // cout << fu << ' ' << cnt << endl;
    // cout << query(root, 1, (int)1e9, fu) << endl;
    while(m--){
        int x,v;
        cin >> x >> v;
        if(a[x] > 0)update(root, 1, (int)1e9, a[x], -1);
        else fu += a[x], --fu_cnt;
        a[x] = v;
        if(a[x] > 0)update(root, 1, (int)1e9, a[x], 1);
        else fu -= a[x], ++fu_cnt;
        cout << query(root, 1, (int)1e9, fu) + 1 << endl;
    }
    // cout << "DEBUG" << endl;







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
}