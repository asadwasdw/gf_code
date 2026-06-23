#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

const int N  = 2000, M = N * N +10 ;
//vector<vector<int>>edg(N);

int h[N],e[M],ne[M],f[M],idx;
int d[N],cur[N];

int S,T;
int n;
double D;
PII no[N];
int sum = 0;

bool check(PII a, PII b){
    return (a.first -  b.first) * (a.first -  b.first) + (a.second -  b.second) * (a.second -  b.second) <= D*D;
}

void add(int a, int b, int c) {
   // cout << a <<' '<< b <<' '<< c <<endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}


bool bfs() {
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
                if(v == T)return true;
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
        cur[u] = i;
        int v = e[i];

        if(d[v] == d[u] + 1 && f[i]) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) d[v] = -1;
            flow += t, f[i] -= t, f[i ^ 1] += t;
        }
    } 
    return flow;
}

int dinic() {
    int ans = 0,t;
    while(bfs()) if(t = find(S,INF)) ans += t;
    return ans;
}

bool check2(int t) {
    T = t;
    for(int i = 0; i < idx; i += 2) {
        f[i] += f[i ^ 1];
        f[i ^ 1] = 0;
    }
    int ans = dinic();
    return ans >= sum;
}

void solve()
{
    memset(h, -1, sizeof h);
    idx = S = sum = 0;
    cin >> n >> D;
    for(int i = 1; i <= n; i++) {
        
        int x, y, k, m;
        cin >> x >> y >> k >> m;

        no[i] = {x,y};
        add(i, n + i, m);
        add(S, i, k);

        for(int j = 1; j < i; j++) { 
            if(check(no[i], no[j])) {
                add(i + n, j, INF);
                add(j + n, i , INF);
            }
        }
        sum += k;
    }

    vector<int>ans;
 
    for(int i = 1; i <= n; i++) {
        if(check2(i)) ans.push_back(i - 1);
    }
    if(ans.size() == 0) ans.push_back(-1);
    for(auto t:ans) cout << t << ' ';
    cout<<"\n";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}