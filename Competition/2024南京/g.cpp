#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

#define x first
#define y second


int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int x; cin >> x;
    return x;
}

void ANS(int x) {
    cout << "! " << x << endl;
    return;
}

void solve()
{
	
    int n; cin >> n;
    vector<vector<int>>adj(n + 10);
    for(int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        if(x)adj[x].push_back(i);
        if(y)adj[y].push_back(i);
        if(x)adj[i].push_back(x);
        if(y)adj[i].push_back(y);
    }
    vector<int> root;
    vector<int> sz(n + 1);
    vector<int> st(n + 1);
    vector<int> maxs(n + 1);
    int s = 0;
    int mx = s + 1;

    auto dfs = [&](auto self, int u, int fa) -> void {
        s ++;
        for(auto v : adj[u]) {
            if(v == fa) continue;
            if(st[v]) continue;
            self(self, v, u);
        }
    };

    auto dfs1 = [&](auto self, int u, int fa) -> void {
        sz[u] = 1;
        maxs[u] = 0;

        for(auto v : adj[u]) {
            if(v == fa) continue;
            if(st[v]) continue;
            self(self, v, u);
            sz[u] += sz[v];
            maxs[u] = max(maxs[u], sz[v]);
        }

        maxs[u] = max(maxs[u], s - sz[u]);
        if(maxs[u] < mx) {
            mx = maxs[u];
            root.clear();
            root.push_back(u);
        }
        else if(maxs[u] == mx) {
            root.push_back(u);
        }
    };

    auto bj  = [&](int x) -> void {
        // cout << x << " ---- " << y << endl;
        st[x] = 1;
        return; 
    };


    int rt = 1;
    int cnt = 1;
    while(cnt ++) {
        assert(cnt <= 1000);
        s = 0;
        dfs(dfs,rt, 0);
        mx = s + 1;


        dfs1(dfs1, rt, 0);
        // cout << cnt << " -- " << root.size() << endl;
        // for(auto t : root) cout << t << " ";
        // cout << endl;
    

        if(root.size() == 1) {
            rt = root[0];
            vector<int> son;
            for(auto v : adj[rt]) if(st[v] == 0)son.push_back(v); 
            sort(son.begin(), son.end(), [&](int a, int b) {
            	return sz[a] > sz[b];
			}); 
            
		    // for(auto t : root) cout << t << " ";
		    // cout << endl;
			    
            if(son.size() == 3) {
                int T = ask(son[0], son[1]);
                if(T == 0) {
                    bj(rt);
                    rt = son[0];
                } else if(T == 2) {
                    bj(rt);
                    rt = son[1];      
                } else {
                    bj(son[0]);
                    bj(son[1]);
                    rt = son[2];
                }

            } else if(son.size() == 2) {
                int T = ask(son[0], son[1]);
                if(T == 1) {
                    ANS(rt);
                    return;
                } else if(T == 0) {
                    bj(rt);
                    rt = son[0];
                } else if(T == 2) {
                    bj(rt);
                    rt = son[1];
                }

            } else if(son.size() == 0){
                ANS(rt);
                return;
            } else assert(false);


        } else if(root.size() == 2) {
            int T = ask(root[0], root[1]);
            assert(T != 1);

            if(T == 0) {
                bj(root[1]);
                rt = root[0];
            } else {
                bj(root[0]);
                rt = root[1];
            }
        } 
    }


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
