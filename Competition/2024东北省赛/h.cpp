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
int dfn[N],fa[N][21],dep[N],l[N],r[N];
int now = 0;
void dfs(int x, int father) {
    dep[x] = dep[father] + 1;
    fa[x][0] = father;
    l[x] = ++ now; 
    for(int i = 1; i < 20; i ++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for(auto v : edg[x]) {
        if(v == father) continue;
        dfs(v, x);
    }
    r[x] = now;
}

int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 19; i >= 0 ; i --) {
        if(dep[x] - (1 << i) >= dep[y]) {
            x = fa[x][i];
        }
    }
    if(x == y) return x;


    for(int i = 19; i >= 0 ; i -- ) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int dis(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int getfa(int x, int k) {
    for(int i = 19; i >= 0; i --) {
        if((1 << i) <= k) {
            k -= (1 << i);
            x = fa[x][i];
        }
    }
    return x;
}
int n, m;
int a[N][2];
int c[N];

bool check(int mid) {
    for(int i = 1; i <= m; i ++) {
        if(dis(a[i][0],a[i][1]) <= mid) {
            c[1] += 2;
            continue;
        }
        int L = lca(a[i][0], a[i][1]);

        for(int j = 0; j < 2; j ++) {
            int len = dis(L, a[i][j]);
            if(len > mid) {
                int falen = getfa(a[i][j], mid);
                c[l[falen]] += 1;
                c[r[falen] + 1] -= 1;
            }
            else {
                int falen = getfa(a[i][j ^ 1], dis(a[i][0],a[i][1]) - mid - 1);
                c[1] += 1;
                c[l[falen]] -= 1;
                c[r[falen] + 1] += 1;
            }
        }
    }
    int now = 0;
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        now += c[i];
        mx = max(mx, now);
        c[i] = 0;
    }
    return mx >= 2 * m;
}



void solve()
{
    cin >> n >> m;
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    for(int i = 1; i <= m; i ++) cin >> a[i][0] >> a[i][1];

    dfs(1, 0);
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
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