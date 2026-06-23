#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int n;
int w[N],arr[N],rk[N],f[N];


struct Node
{
    int l, r;
    int a; // 做大头时
    int b; 
    int lazy;
}tr[N << 5];
int cnt = 1;
int root[N];

void push_up(int u) {
    tr[u].a = max(tr[tr[u].l].a, tr[tr[u].r].a);
    tr[u].b = max(tr[tr[u].l].b, tr[tr[u].r].b);
    // cout << tr[u].a << " " << tr[tr[u].l].a << " " << tr[tr[u].r].a << endl;
}

void add(int u, int w) {
    if(!u) return;
    tr[u].a += w;
    tr[u].b += w;
    tr[u].lazy += w;
}

void push_down(int u) {
    if(!tr[u].lazy) return;
    add(tr[u].l, tr[u].lazy);
    add(tr[u].r, tr[u].lazy);
    tr[u].lazy = 0;
}

void modify(int &u, int l, int r, int pos) {
    u = ++ cnt;
    if(l == r) {
        tr[u] = {0, 0, 0, w[pos], 0};
        return;
    }

    // push_down(x);
    int mid = l + r >> 1;
    if(rk[pos] <= mid) modify(tr[u].l, l, mid, pos);
    if(rk[pos] >= mid + 1) modify(tr[u].r, mid + 1, r, pos);
    push_up(u);
}

int merge(int x, int y, int l, int r, int T, int pre, int suf,int &ans) {
    if(!x) {
        ans = max(ans, tr[y].a + pre - T);
        ans = max(ans, tr[y].b + suf - T);
        return y;
    }
    if(!y) return x;
    push_down(x);
    push_down(y);

    int npre = max(pre,tr[tr[x].l].b);
    int nsuf = max(suf,tr[tr[x].r].a);
    int mid = l + r >> 1;
    tr[x].l = merge(tr[x].l, tr[y].l, l, mid, T, pre, nsuf, ans);
    tr[x].r = merge(tr[x].r, tr[y].r, mid + 1, r, T, npre, suf, ans);
    push_up(x);
    return x;
}




void dfs(int u, int fa) {

    for(auto v : edg[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }

    modify(root[u], 1, n, u);
    int sum = 0;
    for(auto v : edg[u]) {
        if(v == fa) continue;
        f[u] += f[v];
        add(root[u],f[v]);
        add(root[v],sum);
        root[u] = merge(root[u], root[v], 1, n, (sum + f[v]), -INF, -INF, f[u]);
        sum += f[v];
    }
}

// void dfs(int u,int fa){
// 	ll sum=0;
// 	for(auto v:edg[u])if(v^fa)dfs(v,u);
// 	modify(root[u],1,n,u);
// 	for(auto v:edg[u])if(v^fa){
	
// 		f[u]+=f[v];
// 		add(root[u],f[v]);
// 		add(root[v],sum);
// 		// cout << f[u] << " ";
// 		root[u]=merge(root[u],root[v],1,n,(f[v] + sum),-INF,-INF,f[u]);
// 		// cout << f[u] << endl;
// 		sum+=f[v];
// 	}	
// }	


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
        arr[i] = i;
    }
    tr[0] = {0, 0, -INF, -INF, 0};
    sort(arr + 1, arr + n + 1 ,[&](int x, int y) {return  w[x] < w[y];});
    for(int i = 1; i <= n; i ++) {
        rk[arr[i]] = i;
    }
    // for(int i = 1; i <= n; i ++) cout << w[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++) cout << rk[i] << " \n"[i == n];


    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    dfs(1, 0);

    // for(int i = 1 ; i <= n; i ++) cout << f[i] << " \n"[i == n];

    cout << f[1] << endl;
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