#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int S,T;
struct Node{
    int in, to, dp;
}node[N];
int a[N];

int h[N], ne[N], e[N], f[N], idx;
int d[N], cur[N];
void add(int a, int b, int c) {
    //cout<<a<<" "<<b<<" "<< c << endl;
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}

bool bfs() { 
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S]  = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i ; i = ne[i]) {
            int v = e[i];
            if(d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v == T)return true;
                q.push(v);
            }
        }
    }
    return false;
}


int find(int u,int limit) {
    if(u == T) return limit;

    int flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;
        if(d[v] == d[u] + 1 && f[i]) {
            int t = find(v,min(f[i], limit - flow));
            if(!t) d[v] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t; 
        }
    }
    return flow;
}

int dinic(){
    int ans = 0,t;
    while(bfs()) if(t = find(S, INF)) ans += t;
    return ans;
}


void solve()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    S = 0, T = 2 * n + 1;
    int s = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], node[i] = {2 * i - 1,2 * i};
    for (int i = 1;i <= n; i++) {
        for(int j = 0 ;j < i; j++) {
            if(a[i] >= a[j]) node[i].dp = max(node[i].dp, node[j].dp + 1);
        }
        s = max(s, node[i].dp);
    }

   // for(int i = 1; i <= n; i++) cout << node[i].in <<" "<<node[i].to <<endl;
    cout << s << endl;

    if(s == 1) {
        cout << n <<"\n"<< n <<endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(node[i].dp == node[j].dp - 1 && a[i] <= a[j]) {
                //cout<<i<<" "<<j<<endl;
                add(node[i].to, node[j].in, 1);
            }
        }
        add(node[i].in, node[i].to, 1);
        if(node[i].dp == 1) add(S, node[i].in, 1);
        if(node[i].dp == s) add(node[i].to, T ,1);
    }
    int ans1 = dinic();
    cout << ans1 <<endl;

    // memset(h, -1, sizeof h);
    // idx = 0;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = i + 1; j <= n; j++) {
    //         if(node[i].dp == node[j].dp - 1 && a[i] <= a[j]) {
    //             add(node[i].to, node[j].in, 1);
    //         }
    //     }

    //     int x = 1;
    //     if(i == 1 || i == n) x = INF; 
    //     add(node[i].in, node[i].to, x);

    //     if(node[i].dp == 1) add(S, node[i].in, x);
    //     if(node[i].dp == s) add(node[i].to, T ,x);
    // }
    // cout << dinic() <<endl;

    for(int i = 0; i < idx; i += 2) {
        int a = e[i ^ 1], b = e[i];
        if(a == S && b == node[1].in) f[i] = INF;
        if(a == node[1].in && b == node[1].to) f[i] = INF;
        if(a == node[n].in && b == node[n].to) f[i] = INF;
        if(a == node[n].to && b == T) f[i] = INF;
    }
    cout << ans1 + dinic() << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}