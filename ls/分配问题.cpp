#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=100+10,M = N * N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], e[M], ne[M], f[M], w[M], idx;
int d[N], incf[N], pre[N];
bool st[N];

void add(int a, int b, int c, int d) {
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}

void init() {
    for(int i = S; i <= T; i ++) h[i] = -1;
}

void clear() {
    for(int i = 0; i < idx; i += 2) {
        f[i] += f[i ^ 1];
        f[i ^ 1] = 0;
    }
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
    // cout << incf[T] << endl;
    // for(int i = S; i <= T; i ++) cout << incf[i] << " \n"[i == T];
    // for(int i = S; i <= T; i ++) cout << d[i] << " \n"[i == T];
    return incf[T] > 0;
}


bool EK(int& flow, int& cost, int opt) {
    flow = 0, cost = 0;
    clear();
    while(spfa(opt)) {
        int t = incf[T];
        flow += t;
        cost += t * d[T];
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }   
}


void solve()
{
  
    int n;
    cin >> n;
    S = 0, T = 2 * n + 1;
    init();
    
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int x; cin >> x;
            add(i, j + n, 1, x);
        }
        add(S, i, 1, 0);
        add(i + n, T, 1, 0);
    }
    int flow, cost;
    EK(flow, cost, 0);
    cout << cost << endl;
    EK(flow, cost, 1);
    cout << cost << endl;
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