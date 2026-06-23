#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

int n, m, S, T, cnt;
int h[N], ne[N], e[N], f[N], A[N], idx, l[N];
int d[N], cur[N];

void add(int a, int b, int c, int d) {
    l[idx] = c;
    e[idx] = b, f[idx] = d - c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0    , ne[idx] = h[b], h[b] = idx ++; 
}

bool bfs() {
    memset(d,-1,sizeof(int) * T * 4);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size())  {
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
        if(d[v] == d[u] + 1 && f[i]) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) d[v] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

int dinic() {
    int ans = 0;
    int flow;
    while(bfs()) {
        while(flow = find(S, INF))
            ans += flow;
    }
    return ans;
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

void solve()
{
    

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