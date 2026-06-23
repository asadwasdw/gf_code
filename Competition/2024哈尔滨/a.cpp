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

vector<vector<PII>>adj(N);

int idr[N], idl[N], id[N];

void add(int u, int v, int w) {
    if(u == 0 && w == 0) return;
    adj[u].push_back({v, w});
}
vector<int> ans;
void dfs(int u, int st) {
    if(adj[u].size() == 0) {
        ans.push_back(st);
    }

    for(auto [v, w] : adj[u]) {
        dfs(v, st << 1 | w);
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    int m = 20;
    int lcnt = 0, rcnt = 0, cnt = 0;
    int s = 0, t = 1, n = 1;

    vector<array<int,3>> edg;

    {
        bool ks = false;
        bool visl = false;
        for(int i = m; i >= 0; i --) {
            int rt = (r >> i) & 1;
            int lt = (l >> i) & 1;
            
  
            if(lt == 1) visl = true;
            if(rt == 1) rcnt = max(i, rcnt);
            if(lt == 1) lcnt = max(i, lcnt);
            
            if(rt == 1 && lt == 1 && ks == false) {
                if(i == 0) {
                    idl[i] = idr[i] = t;
                } else idl[i] = idr[i] = ++ n;
                add(idl[i + 1], idl[i], 1);

            } else if(rt == 1 && lt == 0 && ks == false) {
                if(i == 0) {
                    idl[i] = idr[i] = t;
                } else {
                    if(visl)idl[i] = ++ n;
                    idr[i] = ++ n;
                }
                add(idr[i + 1], idr[i], rt);
                add(idl[i + 1], idl[i], lt);
                ks = true;
            } else if(ks) {
                if(i == 0) {
                    idl[i] = idr[i] = t;
                } else {
                    if(visl)idl[i] = ++ n;
                    idr[i] = ++ n;
                }

                add(idr[i + 1], idr[i], rt);
                if(rt == 1) {
                    cnt = max(i, cnt);
                    edg.push_back({idr[i + 1], i, !rt});
                    // if(lcnt == rcnt) add(idr[i + 1], idr[i], !rt);
                }

                if(visl) {
                    add(idl[i + 1], idl[i], lt);
                    if(lt == 0) {
                        cnt = max(i, cnt);
                        edg.push_back({idl[i + 1], i, !lt});
                        // if(lcnt == rcnt) add(idl[i + 1], idl[i], !lt);
                    }
                }
            } else if(lt == 0 && rt == 0 && ks == false && rcnt != 0){
                if(i == 0) {
                    idl[i] = idr[i] = t;
                } else {
                    if(visl)idl[i] = ++ n;
                    idr[i] = ++ n;
                }

                add(idr[i + 1], idr[i], rt);
                add(idl[i + 1], idl[i], lt);
            }
        }
    }

    {
        if(1) {
            if( rcnt - lcnt <= 1) rcnt = 0;
            for(int i = max(cnt,rcnt - 1); i >= 0; i --) {
                if(i == 0) id[i] = t;
                else id[i] = ++n;
            }

            for(int i = max(cnt,rcnt - 1) - 1; i >= 0; i --) {
                add(id[i + 1], id[i], 1);
                add(id[i + 1], id[i], 0);
                if(lcnt <= i && i < rcnt) add(s, id[i + 1], 1);
            }

            for(auto [u, v, w] : edg) {
                add(u, id[v], w);
            }
        }

        
    }

    cout << n + 1 << endl;
    for(int i = 0; i <= n; i ++) {

        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());

        cout<< adj[i].size();
        for(auto [v, w] : adj[i]) cout << " " << v + 1 << " " << w;
        cout << endl;
    }


    // for(int i = 0; i <= n; i ++) {
    //     for(auto [v, w] : adj[i]) cout << i << " " << v << " " << w << endl; 
    // }

    // dfs(0, 0);
    // sort(ans.begin(), ans.end());
    // ans.erase(unique(ans.begin(), ans.end()), ans.end());

    // for(auto t : ans) cout << t << " "; cout << endl;


    

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