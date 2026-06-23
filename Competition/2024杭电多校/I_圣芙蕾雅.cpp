#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int n,m;
int opt[N], per[N];


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> opt[i] >> per[i];
    }

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        edg[v].push_back(u);
    }
    vector w(n + 10, 0);

    for(int i = 1; i <= k; i ++) {
        vector st(n + 10, 0);
        queue<int> q;
        for(int j = 1; j <= n; j ++) {
            if(opt[j] == 2 && per[j] == i) {
                q.push(j);
                st[j] = 1;
            }
        }

        while(q.size()) {
            int v = q.front(); q.pop();
            w[v] ++;
            for(auto u : edg[v]) {
                if(st[u]) continue;
                if(opt[u] == 1 && per[u] == i) continue;

                st[u] = true;
                q.push(u);
            }
        }
    }

    // for(int i = 1; i <= n; i ++) cout << w[i] << " \n"[i == n];

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        edg[i].clear();
        ans = max(ans, w[i] + (opt[i] == 1));
    }
    cout << ans << endl;









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