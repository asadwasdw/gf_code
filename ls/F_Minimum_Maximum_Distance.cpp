#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
bool mark[N];
int n,m;
int dis[N];
int bfs(int x)
{
    queue<int>q;

    for(int i = 1; i <= n; i++)dis[i] = -1;

    dis[x] = 0;
    q.push(x);

    while(q.size()) {
        int u = q.front(); q.pop();

        for(auto v : edg[u]) {
            if(dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        } 
    }
    int ans = x;
    for(int i = 1;i<=n;i++){
        if(mark[i] && dis[i] > dis[ans])ans = i;
    }
    return ans;
}

void solve()
{
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        edg[i].clear();
        mark[i] = false;
    }
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        mark[x] = true;
    }
    for(int i = 1; i < n; i++) {
        int a,b; cin >> a >> b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    int p = bfs(1);
    int q = bfs(p);
    //cout << p << " " << q << endl;
    cout << (dis[q] + 1) / 2 <<endl;
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