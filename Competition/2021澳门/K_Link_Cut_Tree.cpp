#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int fa[N];
int find(int k){
    return k == fa[k] ? k : fa[k] = find(fa[k]);
}
bool merge(int a, int b){
    int f1 = find(a), f2 = find(b);
    if(f1 == f2)return true;
    fa[f2] = f1;
    return false;
}
bool st[N];
vector<int> res, ans;
vector<PII> g[N];
void dfs(int u, int y, int fa){
    st[u] = true;
    for(auto [v, id] : g[u]){
        if(v == fa)continue;
        if(st[v]){
            if(u == y && ans.size() < 3){
                ans = res;
                ans.push_back(id);
            }   
            continue;
        }
        res.push_back(id);
        dfs(v, y, u);
        res.pop_back();
    }
    
}
void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)fa[i] = i, g[i].clear(), st[i] = false;
    bool f = false;
    res.clear();
    ans.clear();
    for(int i=1; i<=m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        if(merge(u, v) && !f){
            dfs(u, v, -1);
            if(ans.size() > 2)f = true;
        }
    }
    if(f){
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); ++i)cout << ans[i] << " \n"[i == ans.size()-1];
    }
    else cout << -1 << endl;






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}