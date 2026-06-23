#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
vector<vector<int>>edg(N);
int n, m;

void dfs(int u, int fa, int banch) {
    for(auto v : adj[u]) {
        if(v == fa) continue;
        if(v <= m) {
            // cout << banch << " " << v << endl;
            edg[banch].push_back(v);
        }
        else {
            int b = v;
            if(adj[v].size() == 2) b = banch;
            if(b == v) edg[banch].push_back(v);
            // cout << v << " " << b << endl;
            dfs(v, u, b);
        }
    }
}

int depth[N];
vector<int> dep[N];
vector<int> s[N];

void dfs2(int u, int d) {
    depth[u] = d;
    if(u <= m) {
        s[u].push_back(u);
        return;
    }

    for(auto v : edg[u]) {
        dfs2(v, d + 1);
        for(auto t : s[v]) {
            s[u].push_back(t);
        }
    }
    dep[d].push_back(u);
}


bool check(int x, int y) {
    // cout << x << " - " << y << endl;
    // for(auto t : s[x]) cout << t << " "; cout << endl;
    // for(auto t : s[y]) cout << t << " "; cout << endl;
    if(s[x].size() != s[y].size()) return false;

    {
        bool pp = true;
        for(int i = 0; i < s[x].size() && pp; i ++) {
            if((s[y][i]) % m != (s[x][i] + 1) % m) pp = false;
        }

        if(pp) return true;
    }

    {
        bool pp = true;
        for(int i = 0; i < s[x].size() - 1 && pp; i ++) {
            if((s[y][i + 1]) % m != (s[x][i] + 1) % m) pp = false;
        }
        if(((s[x][s[x].size() - 1] + 1) % m) != (s[y][0]) % m) pp = false;
        if(pp) return true;
    }

    return false;
}

bool win = true;
void dfs3(int x, int y) {
    // cout << x << " " << y << endl;
    if(!win) return;

    for(auto xv : edg[x]) {
        bool cg = false;
        for(auto yv : edg[y]) {
            if(check(xv, yv)) {
                cg = true;
                dfs3(xv, yv);
                break;
            }
        }
        if(!cg) {
            win = false;
            // cout << xv << " " << y << endl;
        }
    }
}


void solve()
{

    cin >> n >> m;
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i = 1; i <= n; i ++) cout << adj[i].size() << endl;
    dfs(n, 0, n);

    for(int i = 1; i <= n; i ++) {
        for(auto v : edg[i]) cout << i << " " << v << endl;
    }

    dfs2(n, 1);


    for(int i = 1; i <= n; i ++) {
        // cout << i << "---\n";
        sort(s[i].begin(), s[i].end());
        for(int j = 1; j < s[i].size(); j ++) {
            if(s[i][j] != s[i][j - 1] + dep[depth[i]].size()) win = false;
        }
        // for(auto t : s[i]) cout << t << " "; cout << endl;
    }

    // for(int i = 1; i <= n; i ++) cout << depth[i] << " "; cout << endl;

    for(int i = 1; i <= m; i ++) {
        if(depth[i] != depth[1]) win = false;
    }

    dfs3(n, n);

    // cout << check(9, 7) << endl;

    if(win) cout << "Doddle\n";
    else cout << "Tie\n";

    for(int i = 1; i <= n; i ++) {
        depth[i] = 0;
        adj[i].clear();
        edg[i].clear();
        dep[i].clear();
        s[i].clear();
    }

    win = true;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}