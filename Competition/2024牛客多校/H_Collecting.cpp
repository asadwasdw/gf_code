#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
//vector<vector<int>>edg(N);


const int N=2e5 + 10, M = 2e5 + 10;
int S, T, cnt, numS, numT, p, q, n , m;
int h[N], e[M], f[M], w[M], ne[M], idx;
int d[N]; // 到某个点单位流量的最小花费
int pre[N]; // 记录每个点的来路的编号
int incf[N]; // 到每个点的流量
bool st[N];
int F[N]; // 记录到每个点的流量

void add(int a, int b, int c, int d) { // a -> b 容量是c, 单位价格是 d
    // cout << a << " " << b << " " << c << " " << d << endl;
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, w[idx] = d,  ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}

bool spfa(int opt) {
    // 0 最小值
    // 1 最大值
    queue<int> q;
    memset(incf, 0, sizeof incf);
    memset(d, (opt == 0 ? 0x3f : -0x3f), sizeof d);
    q.push(S), d[S] = 0, incf[S] = INF;

    while(q.size()) {
        int u = q.front(); q.pop();
        st[u] = false;
        // cout << u << endl;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && (opt == 0 ? d[v] > d[u] + w[i] : d[v] < d[u] + w[i])) {
                d[v] = d[u] + w[i];
                incf[v] = min(incf[u], f[i]);
                pre[v] = i;
                if(!st[v]) {
                    st[v] = true;
                    q.push(v);
                }
            }
        }
    }
    // cerr << incf[T] << endl;
    // cout << incf[T] << endl;
    // for(int i = S; i <= T; i ++) cout << incf[i] << " \n"[i == T];
    // for(int i = S; i <= T; i ++) cout << d[i] << " \n"[i == T];
    return  incf [T] > 0;
}



int flow, cost;
void EK(int opt) { 
    // 0 最大流下最小值
    // 1 最大流下最大值
    flow = cost = 0;

    // spfa(opt);
    while(spfa(opt)) {
        int t = incf[T]; // 此时流量
        flow += t, cost += t * d[T];
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
    // for(int i = S; i <= T; i ++) cout << F[i] << " \n"[i == T];
    // for(int i = S; i <= T; i ++) cout << i << " " <<  F[i] << "\n";
    // cout << flow << " " << cost << endl;
}

void clear() {
    memset(h, -1, sizeof h);
    idx = 0;
    cnt = 0;
}

int newnode() {
    return cnt ++;
}

vector<int> createNode(int k) {
    vector<int> res;
    while(k --) {
        res.push_back(newnode());
    }
    return res;
}

int id[N][2];

void solve()
{
    int k;
    cin >> n >> m >> k;
    S = newnode();
    for(int i = 1; i <= n; i ++) {
        id[i][0] = newnode();
        id[i][1] = newnode();
        add(id[i][0], id[i][1], k, 0);
    }
    int t1 = newnode();
    T = newnode();
    
    add(S, id[1][0], k, 0);
    add(t1, T, k, 0);

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        add(id[u][1], id[v][0], k, 0);
    }

    for(int i = 1; i <= n; i ++) {
        int w; cin >> w;
        add(id[i][0], id[i][1], 1, w);
    }
    
    for(int i = 1; i <= n; i ++) {
        add(id[i][1], t1, k, 0);
    }

    EK(1);
    cout << flow << " " << cost << endl;
}


signed main()
{
    clear();
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