#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
vector<int> g[N];

int dis[N];

void dfs1(int u, int fa, int d){
    dis[u] = d;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs1(v, u, d + 1);
    }
}
vector<int> ans;
void dfs(int u, int fa){
    ans.push_back(u);
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs(v, u);
    }
}
void solve(){
    int n;cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, -1, 0);
    int s = 1;
    for(int i = 1; i <= n; i++){
        if(dis[i] > dis[s]) s = i;
    }
    dfs1(s, -1, 0);
    int t = 1;
    for(int i = 1; i <= n; i++){
        if(dis[i] > dis[t]) t = i;
    }
    if(dis[t] <= 2){
        cout << "NO\n";
        return;
    }

    //s = g[s][0];
    dfs(s, -1);
    cout << "YES\n";
    swap(ans[0], ans[1]);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i==n-1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
}