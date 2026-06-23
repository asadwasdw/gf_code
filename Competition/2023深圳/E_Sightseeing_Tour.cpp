#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

ll d[500][500];
struct {
    int u, v, w;
} edg[N];
void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INFll/5;
        }
    }
    for(int i = 1; i <= m; i ++) {
        ll a, b, t;
        cin >> a >> b >> t;
        edg[i] = {a, b, t};
        d[a][b] = d[b][a] = min(d[a][b], t);
    }

    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= n; j ++) {
    //         cout << d[i][j] << " \n"[j == n];
    //     }
    // }
    int q; cin >> q;

    while(q --) {
        int v[10];
        int cnt; cin >> cnt;
        for(int i = 1; i <= cnt; i ++) cin >> v[i];
        // for(int i = 1; i <= cnt; i ++) cout << v[i] << " \n"[i == cnt];
        
        // sort(v + 1, v + cnt + 1);
        ll ans = INFll;
        do{
            for(int st = 0; st < (1 << cnt); st ++) {
                ll res = 0;
                int last = 1;
                for(int i = 1; i <= cnt; i ++) {
                    if((st >> (i - 1)) & 1) {
                        res += d[last][edg[v[i]].u];
                        last = edg[v[i]].v;
                    } else {
                        res += d[last][edg[v[i]].v];
                        last = edg[v[i]].u;
                    }
                    res += edg[v[i]].w;
                }
                res += d[last][n];
                // cout << res << endl;
                ans = min(ans, res);
            }
        }while(next_permutation(v + 1, v + cnt + 1));
        cout << ans << endl;
    }







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