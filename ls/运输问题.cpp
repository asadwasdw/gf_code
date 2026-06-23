#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
const int N = 510, M = 1e5 + 10;
int n, m, S, T;
int h[N], e[M], ne[M], f[M], w[M], idx;
int d[N], incf[N], pre[N];
bool st[N];

void add(int a, int b, int c, int d) {
    // cout << a << " " << b << " " << c << " " << d << endl;
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}

bool spfa() {
    queue<int> q;
    memset(d, 0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    q.push(S), d[S] = 0, incf[S] = INF;

    while(q.size()) {
        int u = q.front(); q.pop();
        st[u] = false;
      
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] > d[u] + w[i]) {
                d[v] = d[u] + w[i];
                pre[v] = i;
                incf[v] = min(f[i], incf[u]);
                if(!st[v]) {
                    st[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return incf[T] > 0;
}

void EK(int& flow, int& cost) {
    flow = cost = 0;
    while(spfa()) {
        
        int t = incf[T];
        flow += t;
        cost += t * (d[T]);
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
}


bool spfa2() {
    queue<int> q;
    memset(d, -0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    q.push(S), d[S] = 0, incf[S] = INF;

    while(q.size()) {
        int u = q.front(); q.pop();
        st[u] = false;
      
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] < d[u] + w[i]) {
              
                d[v] = d[u] + w[i];
                pre[v] = i;
                incf[v] = min(f[i], incf[u]);
                if(!st[v]) {
                    st[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return incf[T] > 0;
}

void EK2(int& flow, int& cost) {
    flow = cost = 0;
    while(spfa2()) {
        
        int t = incf[T];
        flow += t;
        cost += t * (d[T]);
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
}




void solve()
{
    cin >> m >> n;
    S = 0, T = m + n + 1;
    // vector<vector<int>> a(m + 10, vector<int>(n + 10, 0));

    for(int i = 1; i <= m; i ++) {
        int x; cin >> x;
        add(S, i, x, 0);
    }

    for(int i = m + 1; i <= m + n; i ++) {
        int x; cin >> x;
        add(i, T, x, 0);
    }

    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) 
        {
            int x; cin >> x;
            add(i, m + j, INF, x);
        }
    }

    int flow,cost;
    EK(flow, cost);
    cout << cost << endl;
    for(int i = 0; i < idx; i += 2) {
        f[i] += f[i ^ 1];
        f[i ^ 1] = 0;
    }

    EK2(flow, cost);
    cout << cost << endl;

}


signed main()
{
    memset(h, -1, sizeof h);
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