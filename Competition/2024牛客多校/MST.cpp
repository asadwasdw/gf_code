#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<array<int,3>>edg;
map<PII,int> e;

int f[N];
int a[N];
int id[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(u > v) swap(u, v); // 小向大建边
        edg.push_back({w, u, v});
        
        e[{u,v}] = w;
    }

    sort(edg.begin(), edg.end(),[&](array<int,3> A, array<int,3> B){
        return A[0] < B[0];
    });
    int nn = sqrt(n);

    while(q --) {
        int k; cin >> k;
        vector<array<int,3>> E;

        for(int i = 1; i <= k; i ++) {
            cin >> a[i];
            f[i] = i;
            id[a[i]] = i;
        }
  
            
        if(k <= nn + 1) {
            for(int i = 1; i <= k; i ++) {
                for(int j = i + 1; j <= k; j ++) {
                    int u = a[i], v = a[j];
                    if(u > v) swap(u, v);
                    if(e[{u, v}]) {
                        E.push_back({e[{u, v}], i, j});
                    }
                }
            }


            sort(E.begin(), E.end(),[&](array<int,3> A, array<int,3> B){
                return A[0] < B[0];
            });

        }
        else {
            for(auto [w, u, v]: edg) {
                int a = find(u), b = find(v);
                if(id[u] && id[v]) {
                    E.push_back({w, id[u], id[v]});
                }
            }
        }


   
        ll ans = 0;

        for(auto [w, u, v] : E) {
            u = find(u);
            v = find(v);
            if(u != v) f[u] = v, ans += w;
        } 
        int cnt = 0;
        for(int i = 1; i <= k; i ++) {
            if(find(i) == i) cnt ++;
            id[a[i]] = 0;
        }
        if(cnt != 1) ans = -1;
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