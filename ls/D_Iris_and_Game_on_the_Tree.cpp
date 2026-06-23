#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
int fa[N], d[N];
string c;
struct Node{
    int w, dep, id;
}q[N];
int cnt = 0;

int dfs(int u, int father) {
    fa[u] = father;
    d[u] = d[father] + 1;
    int res = 0;
    for(auto v : adj[u]) {
        if(v == father) continue;
        res += dfs(v, u);
    }
      
    if(adj[u].size() == 1 && u != 1) {
        res = 1;
    }
    
    if(c[u] == '?') {
        q[++cnt] = (Node){res, d[u], u};
    }

    return res;
}
int ans = 0;

void dfs2(int u, int a, int b) {
    if(u != 1 && adj[u].size() == 1) {
        ans += a - b;
    } 
    
    for(auto v : adj[u]) {
        if(v == fa[u]) continue;
        int ta = a, tb = b;
        if(c[u] == '1' && c[v] == '0') ta ++;
        if(c[u] == '0' && c[v] == '1') tb ++;
        dfs2(v, ta, tb);
    }
}



void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> c;
    c = " " + c;

    dfs(1, 0);

    sort(q + 1, q + cnt + 1, [&](Node a, Node b){
        if(a.w != b.w) return a.w > b.w;
        return a.dep < b.dep;
    });


    for(int i = 1; i <= cnt; i ++) {
        cout << q[i].w << " " << q[i].dep << " " << q[i].id << endl;
        if(i == 1 && q[i].id == 1) {
            c[i] = '1';
            continue;
        }

        if(i%2 == 1) {
             c[q[i].id] = '0';
            
        }
        else {
            c[q[i].id] = '1';
        }
    }
    cout << c << endl;

    dfs2(1, 0, 0);
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