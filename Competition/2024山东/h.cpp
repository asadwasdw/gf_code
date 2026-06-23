#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,PII>PIII;
const int N=2e5+10, M = N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

PIII L[N], R[N];
int lcnt, rcnt;
int S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];
bool st[N];
PII res[N];

void clear() {
    // cout << S << " " << T << endl;
    for(int i = 0; i < N; i ++) {
        h[i] = -1;
        ne[i] = e[i] = f[i] = d[i] = cur[i] = 0;
        st[i] = false;
        R[i] = L[i] = {{0,0},{0,0}};
        res[i] = {0,0};
    }
    S = 0, T = 0;
    lcnt = rcnt = idx = 0;
}

void print(PIII t) {
    cout << t.x.x << " " << t.x.y << " | " << t.y.x << " " << t.y.y << endl;
}

PII pd2(PIII a, PIII b) {
    int resx = 0, resy = 0;
    if(b.first.x < a.first.x && a.first.x < b.second.x) resx = a.first.x;
    if(a.first.y < b.first.y && b.first.y < a.second.y) resy = b.first.y;
    return {resx, resy};
}


void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    // memset(d, -1, sizeof(int) * (T + 10));
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int find(int u, int limit) {
    if(u == T) return limit;
    int flow = 0;

    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;
        if(d[v] == d[u] + 1 && f[i]) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) cur[u] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

ll dinic() {
    ll ans = 0, flow;
    while(bfs())
        if(flow = find(S, INF))
            ans += flow;
    return ans;
}

void solve()
{
    unordered_map<int,vector<PII>> row, col;
    row.clear();
    col.clear();

    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        row[x].push_back({y,1});
        col[y].push_back({x,1});
    }

    int m; cin >> m;
    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        row[x].push_back({y,0});
        col[y].push_back({x,0});
    }

    bool ky = true;
    for(auto &[i,t] : row) {
        sort(t.begin(), t.end());
        for(int j = 1; j < t.size(); j ++) {
            if(t[j].second == 0 || t[j - 1].second == 0) continue;
            if(t[j].first == t[j - 1].first + 1) ky = false;
            L[++lcnt] = {{i, t[j - 1].first}, {i, t[j].first}};
        }
    }

    for(auto &[i,t] : col) {
        sort(t.begin(), t.end());
        for(int j = 1; j < t.size(); j ++) {
            if(t[j].second == 0 || t[j - 1].second == 0) continue;
            if(t[j].first == t[j - 1].first + 1) ky = false;
            R[++rcnt] = {{t[j - 1].first, i}, {t[j].first, i}};
        }  
    }


    
    if(!ky) {
        cout << "-1\n";
        return;
    }
    S = 0, T = lcnt + rcnt + 1;;
    for(int i = 1; i <= lcnt; i ++) {
        // print(L[i]);
        add(S, i, 1);
    } 
    for(int i = 1; i <= rcnt; i ++) {
        // print(R[i]);
        add(i + lcnt, T, 1);
    }

    for(int i = 1; i <= lcnt; i ++) {
        for(int j = 1; j <= rcnt; j ++) {
            PII T = pd2(L[i], R[j]);
            if(T.x == 0 || T.y == 0) continue;
            res[idx] = T;
            add(i, j + lcnt, 1);
        }
    }

    dinic();

    vector<PII> ans;
    // cout << lcnt << " " << T << endl;
    for(int i = 0; i < idx; i += 2) {
        int v = e[i], u = e[i ^ 1];
        if(0 < u && u <= lcnt && lcnt < v && v < T && f[i ^ 1]) {
            //  cout << u << " " << v << " " << f[i ^ 1] << " " << endl;
            // cout << res[i].x << " " << res[i].y << endl;
            ans.push_back(res[i]);
            st[u] = st[v] = true;
        }
    }

    for(int i = 1; i <= lcnt; i ++) {
        if(!st[i]) {
            ans.push_back({L[i].x.x, L[i].x.y + 1});
            // cout << L[i].x.x << " " << L[i].x.y + 1 << endl;
        }
    }


    for(int i = 1; i <= rcnt; i ++) {
        if(!st[i + lcnt]) {
            ans.push_back({R[i].x.x + 1, R[i].x.y});
            // cout << R[i].x.x + 1 << " " << R[i].x.y << endl;
        }
    }

    cout << ans.size() << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;
}


signed main()
{
    memset(h, -1, sizeof h);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
        clear();
    }
}