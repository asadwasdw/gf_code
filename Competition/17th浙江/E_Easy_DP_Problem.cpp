#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n,m;
int a[N];

int root[N], cnt;
struct node
{
    int l,r;
    int val, sum;
}tr[N << 2];

void update(int pre, int &k, int l, int r, int x){
    k = ++cnt;
    tr[k].l = tr[pre].l, tr[k].r = tr[pre].r;
    tr[k].val = tr[pre].val + 1, tr[k].sum = tr[pre].sum + x;
    if(l == r){
        return;
    }
    int mid = l + r >> 1;
    if(mid >= x)update(tr[pre].l, tr[k].l, l, mid, x);
    else
    update(tr[pre].r, tr[k].r, mid+1, r, x);
}

int query(int pre, int k, int l, int r, int x){
    int mid = l + r >> 1;
    if(l == r)return l*x;
    int temp = tr[tr[k].l].val - tr[tr[pre].l].val;
    int w = tr[tr[k].l].sum - tr[tr[pre].l].sum;
    if(temp >= x)return query(tr[pre].l, tr[k].l, l, mid, x);
    return query(tr[pre].r, tr[k].r, mid + 1, r, x - temp) + w;
}

int p[N], s[N];

void solve()
{
    int M = 1e6;
    cin >> n;
    cnt = 0;
    for(int i=1; i<=n; ++i)cin >> a[i], update(root[i-1], root[i], 1, M, a[i]), s[i] = s[i-1] + a[i];
    cin >> m;
    while (m--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        int len = r - l + 1;
        int res = 0;
        if(len - k > 0)res = query(root[l-1], root[r], 1, M, len - k);
        // cout << res << ' ';
        cout << (s[r] - s[l-1]) - res + p[len] << '\n';
    }
    





}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    for(ll i=1; i<=1e5; ++i)p[i] = p[i-1] + i*i;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}