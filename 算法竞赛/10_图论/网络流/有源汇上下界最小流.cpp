#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int n,m,S,T;
int h[N],e[N],ne[N],f[N],idx;
int d[N],cur[N],A[N];


void add(int a,int b,int c){
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs(){
    queue<int>q;
    q.push(S);

    memset(d,-1,sizeof d);
    cur[S] = h[S];
    d[S] = 0;

    while(q.size()){
        int u = q.front();q.pop();

        for(int i = h[u]; ~i ; i = ne[i]){

            int v = e[i];
            if(d[v] == -1 && f[i]){
                cur[v] = h[v];
                d[v] = d[u] + 1;

                if(v == T)return true;
                q.push(v);
            }

        }
    }
    return false;
}

int find(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = find(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}


int dinic()
{
    int ans = 0, flow ;
    while(bfs())if(flow = find(S,INF))ans += flow;
    return ans;
}




void solve()
{
    memset(h,-1,sizeof h);
    int s,t;
    cin>>n>>m>>s>>t;

    for(int i = 1;i <= m; i++ ){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        add(a,b,d-c);
        A[a] -= c;A[b] += c;
    }

    S = 0,T = n + 1;
    int tot = 0;
    for(int i = 1;i <= n;i++){
        if(A[i] > 0 ) tot += A[i],add(S, i, A[i]);
        else if(A[i] < 0)add(i, T, -A[i]);
    }

    add(t, s, INF);

    if(dinic() < tot) puts("No Solution");
    else {
        int ans = f[idx - 1];
        f[idx - 1] = f[idx - 2] = 0;
        S = t, T = s;
        cout<<ans - dinic()<<endl; 
    }
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