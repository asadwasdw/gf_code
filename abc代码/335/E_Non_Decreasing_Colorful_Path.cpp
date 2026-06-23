#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
vector<set<int>>edg2(N);

int n,m;
int w[N];

PII e[N];
int cnt = 0;

int f[N];
int find(int x)
{
    if(x!=f[x]) f[x] = find(f[x]);
    return f[x];
}

int d[N];
int dis[N];
int h[N];
void dfs(int u) {
    h[u] = 1;
    for (auto v : edg[u]) if (!h[v]) dfs(v);
}


void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>w[i],f[i]=i;

    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        a=find(a);
        b=find(b);

        if(w[a]==w[b]){
            if(a!=b)f[a]=find(b);
        }
        else {
            e[++cnt]={a,b};
        }
    }


    for (int i = 1; i <= cnt; i++) {
        int u = e[i].first, v = e[i].second;
        u = find(u), v = find(v);
        if (w[u] > w[v]) swap(u, v);
        edg[u].push_back(v);
    }

    dfs(find(1));
    dis[find(1)]=1;

    for (int i = 1; i <= cnt; i++) {
        int u = e[i].first, v = e[i].second;
        u = find(u), v = find(v);
        if (w[u] > w[v]) swap(u, v);
        if (h[u] && h[v]) d[v]++;
    }

    queue<int>q;
    q.push(find(1));

    while(q.size()){
        int u = q.front();q.pop();

        for(auto v:edg[u]){
            --d[v];
            dis[v]=max(dis[v],dis[u]+1);
            if(d[v]==0){
                q.push(v);
            }
        }
    }

    cout<<dis[find(n)]<<endl;

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