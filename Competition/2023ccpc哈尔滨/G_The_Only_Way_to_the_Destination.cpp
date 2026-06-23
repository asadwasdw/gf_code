#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
#define int long long
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

set<pair<int, int>> s[N];
int dep[N], cnt = 0, vis[N];
vector<int> g[N];
map<pair<int, int>, int> mp;
bool ok = true;

void dfs(int u, int fa) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (v == fa) continue;
        if (vis[v]) {
            ok = false;
        }else {
            dfs(v, u);
        }
    }
}

void solve()
{

    int n, m, k;cin >> n >> m >> k;
    
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    
    if (m > 2 * k + 1) {
        cout << "NO\n";
        return;
    }


    for (int i = 1; i <= m; i++) {
        s[i].insert({1ll, n});
    }

    for (int i = 0; i < k; i++) {
        int x1, x2, y; cin >> x1 >> x2 >> y;
        auto it = s[y].upper_bound({x1, n + 1});
        it--;
        int l = it->first, r = it->second;
        s[y].erase(it);
        if (x2 < r){
            s[y].insert({x2 + 1, r});
        }
        if (l < x1) {
            s[y].insert({l, x1 - 1});
        }
    }
    
    for (auto x : s[1]) {
        mp[x] = ++cnt;
    }

    for (int i = 2; i <= m; i++) {
        for (auto x : s[i]) {
            auto it = s[i - 1].upper_bound({x.first, n + 1});
            if (it != s[i - 1].begin()) it--;
            while (it != s[i - 1].end() && it->first <= x.second) {
                int len = max(0ll, min(it->second, x.second) - max(it->first, x.first) + 1);
                if (len > 1) {
                    cout << "NO\n";
                    return;
                }else if (len == 1) {
                    g[cnt + 1].push_back(mp[*it]);
                    g[mp[*it]].push_back(cnt + 1);
                }
                it++;
            }
            mp[x] = ++cnt;
        }
    }

    dfs(1, 0);
    if (ok) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

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