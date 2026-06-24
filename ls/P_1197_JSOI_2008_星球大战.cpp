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

vector<vector<int>>adj(N);

int t[N];
vector<PII> edg;
int ans = 0;
int f[N];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    ans --;
    f[x] = y;
}
int a[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    ans = n;

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        u ++, v ++;
        edg.push_back({u, v});
    }

    int k;
    cin >> k;

    for(int i = 1; i <= n; i ++) {
        f[i] = i;
        t[i] = k + 1;
    }

    for(int i = 1; i <= k; i ++) {
        int x; cin >> x;
        x ++;
        t[x] = i;
        a[i] = x;
        // cout << i << " " << x << endl;
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << t[i] << " \n"[i == n];
    // }

    for(auto [x, y] : edg) {
        if(t[x] == k + 1 && t[y] == k + 1) {
            merge(x, y);
        } else {
            if(t[x] > t[y]) swap(x, y); // 保证x早打击  
            adj[x].push_back(y);
        }
    }
    stack<int> s;
    s.push(ans - k);
    // cout << ans - k << endl;

    for(int i = k; i >= 1; i --) {
        int u = a[i];
        for(auto v : adj[u]) {
            // cout << i << " " << u << " " << v << endl;
            merge(v, u);
        }

        // cout << ans << " " << ans -  (i - 1)  << endl;
        // cout << ans - i + 1 << endl;
        s.push(ans - i + 1);
    }
    while(s.size()) {
        cout << s.top() << endl; s.pop();
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
    return 0;
}