#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
vector<vector<int>>edg2(N);

struct Node {
    int w,x,y;
    bool operator<(const Node& other) const { return w > other.w; }
};

bool st[N][2];
int dis[N][2];
priority_queue<Node>q;

void update(int v,int st, int w) {
    if(dis[v][st] >  w) {
        dis[v][st] = w;
        q.push({dis[v][st],v,st});
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v,w});
    }

    for(int i = 1; i <= n; i ++) {
        for(int j=0;j<edg[i].size();j++)edg2[i].push_back(j);


        sort(edg2[i].begin(), edg2[i].end(), [&](const int &a,const int &b){
            return edg[i][a].second < edg[i][b].second;
        });

        while(edg2[i].size() > 2) {
            edg2[i].pop_back();
        }
    }

    memset(dis,0x3f,sizeof dis);
    update(1,0,0);
   
    while(q.size()) {
        auto [w, u, x] = q.top(); q.pop();
        if(st[u][x])continue;
        st[u][x] = true;
        int k = 0;
        for(auto [v, W] : edg[u]) {
            if(x == 0) {
                update(v,1,w);
                update(v,0,w+W);
            }
            else if(edg2[u].size() >= 2){
                if(k == edg2[u][0]) {
                    update(v,0,w + W + edg[u][edg2[u][1]].second);
                    update(v,1,w + edg[u][edg2[u][1]].second);
                }
                else {
                    update(v,0,w + W + edg[u][edg2[u][0]].second);
                    update(v,1,w + edg[u][edg2[u][0]].second);
                }
            }
            k++;
        }
    }

    // for(int i=1;i<=n;i++)cout <<dis[i][0]<<" "<<dis[i][1]<<endl;
    if(edg2[n].size()) {
        dis[n][1] += edg[n][edg2[n][0]].second;
    }
    else dis[n][1]=INFll;
    int ans =min(dis[n][0],dis[n][1]);
    if(ans >= 1e18) ans = -1;

    cout << ans << endl;





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