#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int n,m,k;
bool st[N];
bool pd(int mid) {
    memset(st, 0 ,sizeof st);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    // st[1]=true;

    while(q.size()) {
        PII T = q.top(); q.pop();
        int u = T.second;
        if(st[u])continue;
        st[u]=true;
        for(auto t:edg[u]) {
            int v = t.first;
            if(st[v])continue;
            int W = 0;
            if(t.second>mid)W++;
            if(W + T.first <= k) q.push({W+T.first, v});
        }
    }

    return st[n];
}

int f[N];
int find(int x)
{
    if(f[x] != x) return f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v, w});
        edg[v].push_back({u, w});
        if(find(u) != find(v)){
            f[find(u)] = find(v);
        }
    }
    // cout << f[1] << " " << f[n] <<"\n";

    if(find(1) != find(n)) {
        cout << "-1";
        return;
    }

    int l = 0, r = 1e6+10;
    while(l < r) {
        int mid = l + r >> 1;
        if(pd(mid))r = mid;
        else l = mid + 1;
    }
    cout<<l<<endl;








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