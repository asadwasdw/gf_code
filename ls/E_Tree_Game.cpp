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
vector<int> d[N];

void dfs(int u, int fa, int dep) {
    d[dep].push_back(u);
    for(auto v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u, dep + 1);
    }
}

void solve()
{
    map<PII,int> mp;
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);

    for(int i = 1; i <= n; i ++) {
        int j = i + 2;
        for(auto u : d[i]) {
            for(auto v : d[j]) {
                if(u > v) swap(u, v);
                cout << u << ' ' << v << endl;
                mp[{u, v}] = true;
            }
        }
    }
    

    if(mp.size() == 0 || mp.size() % 2 == 1) {
        cout << "First\n";
        for(auto [no, st] : mp) {
            if(!st) continue;
            cout << no.first << ' ' << no.second << endl;
            int x, y; cin >> x >> y;
            if(x == -1) break;
            if(x > y) swap(x, y);
            mp[{x, y}] = false;
        } 
    }
    else {
        cout << "Second\n";
        int x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        mp[{x, y}] = false;

        if(x == -1) {
            return;
        }

        for(auto [no, st] : mp) {
            if(!st) continue;
            cout << no.first << ' ' << no.second << endl;
            int x, y; cin >> x >> y;
            if(x == -1) break;
            if(x > y) swap(x, y);
            mp[{x, y}] = false;
        } 
    }










}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}