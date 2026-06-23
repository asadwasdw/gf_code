#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    vector<int> p(N), w(N);
    vector fa(N, vector (25, -1));
    int q;
    cin >> q >> p[0] >> w[0];

    while(q--) {
        int opt; cin >> opt;
        if(opt == 1) {
            int u, v;
            cin >> u >> v;
            cin >> p[u] >> w[u];
            fa[u][0] = v;
            for(int i = 1; i < 20; i ++) {
                if(~fa[u][i - 1]) fa[u][i] = fa[fa[u][i - 1]][i - 1];
            }
        } else if(opt == 2) {
            int k, s;
            cin >> k >> s;
            ll flow = 0, cost = 0;
            while(s > 0 && w[k]) {
                int top = k;
                for(int i = 19; i >= 0; i --) {
                    if(~fa[top][i] && w[fa[top][i]]) top = fa[top][i];
                }
                if(w[top] == -1) w[top] = 0;
                ll t = min(w[top], s);
                s -= t, w[top] -= t;
                flow += t, cost += t * p[top];
            }
            cout << flow << " " << cost << endl;
        } else if(opt == 3) {
            int x; cin >> x; w[x] = -1;
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