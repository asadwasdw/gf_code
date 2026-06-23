#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int n, m, k, s, t;
bool st[N];
int dis[N];
void solve()
{
    memset(dis,0x3f,sizeof dis);
    cin >> n >> m >> k >> s >> t;
    for(int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        for(int j = 0; j <= k; j ++) {
            edg[u+j*n].push_back({v+j*n,w});
            edg[v+j*n].push_back({u+j*n,w});
            if(j!=k){
                edg[u+j*n].push_back({v+j*n+n,0});
                edg[v+j*n].push_back({u+j*n+n,0});
            }
        }
    }

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});
    dis[s]=0;

    int ans = INF;
    while(q.size()) {
        auto T =  q.top();q.pop();
        int u = T.second;
        if(st[u])continue;
        st[u]=true;
        for(auto T:edg[u]) {
            int v = T.first, w = T.second;
            if(dis[u]+w<dis[v]){
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
                if(v%n==t) {
                    // cout << v <<"|"<<dis[v]<<endl;
                    ans=min(ans,dis[v]);
                }
            }
        }
    }
    // cout<<t<<"\n";for(int i = 0;i < k*n+n;i++)cout<<i<<" " <<dis[i]<<"\n";
    cout<<ans<<"\n";








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