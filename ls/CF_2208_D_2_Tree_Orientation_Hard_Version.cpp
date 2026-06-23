#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=8e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

char a[N][N];
int cnt[N];
int f[N];
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

vector<vector<int>>adj(N);
int b[N][N];

void dfs(int u, int root) {
    b[root][u] = 1;
    for(auto v : adj[u]) {
        dfs(v, root);
    }

}


void solve()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        f[i] = i;
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            if(a[i][j] - '0' && i != j) {
                cnt[i] ++;
            }
        }
    }

    queue<int> q;

    for(int i = 1; i <= n; i ++) {
        if(cnt[i] == 0) {
            q.push(i);
        }
    }

    vector<PII> v;

    while(q.size()) {
        int m = q.size();
        while(m --) {
            int u = q.front(); q.pop();
            for(int i = 1; i <= n; i ++) {
                if(a[i][u] == '1' && i != u) {
                    if(-- cnt[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }

        m = q.size();

        while(m --) {
            int u = q.front(); q.pop();
            vector<int> gt(n + 1, 0);
            for(int j = 1; j <= n; j ++) {
                if(a[u][j] - '0' && u != j) {
                    gt[j] = 1;
                }
            }

            for(PII p : v) {
                if(gt[p.x] && gt[p.y]) {
                    gt[p.y] = 2;
                }
            }

            for(int i = 1; i <= n; i ++) {
                if(gt[i] == 1) {
                    v.push_back({u, i});
                }
            }
            if(v.size() >= n) break;
            q.push(u);
        }
        if(v.size() >= n) break;
    }

    bool ky = true;

    for(auto p : v) {
        adj[p.x].push_back(p.y);
        int rx = find(p.x), ry = find(p.y);
        if(rx == ry) ky = false;
        f[rx] = ry;
    }

    for(int i = 1; i <= n; i ++) {
        dfs(i, i);
        for(int j = 1; j <= n; j ++) {
            if(a[i][j] - '0' != b[i][j]) {
                ky = false;
            }
        }
    }

    if(v.size() != n - 1) ky = false;

    if(ky) {
        cout << "Yes\n";
        for(auto p : v) {
            cout << p.x << " " << p.y << endl;
        }
    } else {
        cout << "No\n";
    }


    for(int i = 1; i <= n; i ++) {
        cnt[i] = 0;
        adj[i].clear();
        for(int j = 1; j <= n; j ++) {
            b[i][j] = 0;
        }
    }
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
    return 0;
}