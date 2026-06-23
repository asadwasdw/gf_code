#include<bits/stdc++.h>
// #define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 300000;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
//vector<vector<int>>edg(N);


const int N=1e3 + 10, M = 2e6 + 10;
int S, T, cnt, numS, numT, p, q, n , m;
int h[N], e[M], f[M], ne[M], idx;
double w[M];
double d[N]; // 到某个点单位流量的最小花费
int pre[N]; // 记录每个点的来路的编号
int incf[N]; // 到每个点的流量
bool st[N];
int F[N]; // 记录到每个点的流量

void add(int a, int b, int c, double d) { // a -> b 容量是c, 单位价格是 d
    // cout << a << " " << b << " " << c << " " << d << endl;
    e[idx] = b, f[idx] = c, w[idx] = d,  ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}

bool spfa(int opt) {
    // 0 最小值
    // 1 最大值
    queue<int> q;
    memset(incf, 0, sizeof(int) * T * 4);
    // memset(d, (opt == 0 ? 0x3f : -0x3f), sizeof(int) * T * 4);
    for(int i = S; i <= T; i ++) {
        d[i] = INF * 100;
    }
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
    // cout << incf[T] << endl;
    // for(int i = S; i <= T; i ++) cout << incf[i] << " \n"[i == T];
    // for(int i = S; i <= T; i ++) cout << d[i] << " \n"[i == T];
    return incf[T] > 0;
}



int flow;
double cost;
void EK(int opt) { 
    // 0 最大流下最小值
    // 1 最大流下最大值
    flow = cost = 0;
    while(spfa(opt)) {
        int t = incf[T]; // 此时流量
        // cout << d[T] << endl;
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


PII a[N];
int id[N][2];

void solve()
{
    cin >> n;
    S = newnode();
    for(int i = 1; i <= n ; i ++) {
        cin >> a[i].first >> a[i].second;
        id[i][0] = newnode();
        id[i][1] = newnode();
    }
    T = newnode();

    sort(a + 1, a + n + 1,[&](PII a, PII b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    if(a[1].second == a[2].second) {
        cout << "-1";
        return;
    }

    for(int i = 1; i <= n; i ++) {
        add(S, id[i][0], 2, 0);
        add(id[i][1], T, 1, 0);
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            if(a[i].second > a[j].second) {
                int dx = a[i].first - a[j].first;
                int dy = a[i].second - a[j].second;
                double t = sqrtf(dx * dx + dy * dy);
                add(id[i][0], id[j][1], 1, t);
            }
        }
    }

    EK(0);

    if(flow != n -1) cout << "-1";
    else cout << cost;

    // for(int i = 0; i < idx; i += 2) {
    //     cout << e[i ^ 1] << " - >" << e[i] << " " << f[i ^ 1] << endl;
    //     F[e[i]] += f[i ^ 1];
    // }

    // for(int i = S; i <= T; i ++) cout << F[i] << " \n"[i == T];

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