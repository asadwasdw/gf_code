#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);
vector<vector<int>>fac(N);
vector<vector<int>>edg(N);

int n, k;
int p[N],w;
int vis[N];
int dia = 0, to = 0;
void dfs(int u, int fa, int dis) {
    vis[u] = true;
    // cout << u << " " << dis << endl;
    if(dis > dia) {
        // cout << "S" << endl;
        to = u;
        dia = dis;
    }
    for(auto v : edg[u]) {
        if(v == fa) continue;
        dfs(v, u, dis + 1);
    }
}


void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j += i) {
            fac[j].push_back(i); 
        }
    } // 找所有数j的所有的因子i

    for(int i = 2; i <= n; i ++) {
        cin >> p[i] >> w;
        for(auto t : fac[w]) {
            adj[t].push_back(i); // 这条边可以作为答案是t时的有效边
        }
    }

    for(int ans = n; ans >= 1; ans --) { 
        // 每种边最多作为有效边480次左右
        // cout << adj[ans].size() << endl;
        for(auto x:adj[ans]) {
            int y = p[x];
            // cout << x << " " << y << endl;
            edg[x].push_back(y);
            edg[y].push_back(x);
        }

        for(auto x:adj[ans]) {
            if(vis[x]) continue;
            dia = 0;
            dfs(x, 0, 1);
            dia = 0;
            // cout << to << " ";
            dfs(to, 0, 1);
            // cout << to << " " << dia << endl;

            if(dia >= k) {
                cout << ans << endl;
                return;
            }
        }
        

        for(auto x : adj[ans]) {
            int y = p[x];
            vis[x] = vis[y] = false;
            edg[x].clear();
            edg[y].clear();
        }
    }
    cout << "-1" << endl;






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