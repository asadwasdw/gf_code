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

//vector<vector<int>>adj(N);

int f[N];

int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x]; 
} 

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    f[u] = v;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n + n; i ++) {
        f[i] = i;
    }

    for(int i = 1; i <= m; i ++) {
        char op;
        int u, v;
        cin >> op >> u >> v;
        if(op == 'E') {
            merge(v + n, u);
            merge(u + n, v);
        } else {
            merge(u, v);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(i == find(i)) ans ++;
    }
    cout << ans;
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

/*

3
2
E 1 2
E 2 3

*/