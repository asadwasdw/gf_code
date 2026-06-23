#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=200+10, M = 3010;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], w[M], idx;
int d[N], incf[N], st[N], pre[N];


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
    // for(int i = S; i <= T; i ++) cout << incf[i] << " \n"[i == T];
    return incf[T] > 0;
}

void EK(int& flow, int& cost) {
    flow = cost = 0;
    while(spfa()) {
        int t = incf[T];
        flow += t;
        cost += t * d[T];
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
    // cout << flow << " " << cost << endl;
}


void solve()
{
    cin >> n;
    S = 0, T = n + 1;
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        add(S, i, x, 0);
        int l = i - 1, r = i + 1;
        if(l == 0) l = n;
        if(r == n + 1) r = 1;
        add(i, l, INF, 1);
        add(i, r, INF, 1);
        sum += x;
    }
    sum /= n;
    for(int i = 1; i <= n; i ++) {
        add(i, T, sum, 0);
    }
    int flow, cost;
    EK(flow, cost);
    cout << cost;
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