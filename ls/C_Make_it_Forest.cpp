#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int f[N];

int find(int x) {
    if(f[x] != x) return f[x] = find(f[x]);
    return x;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    f[x] = y;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        merge(u, v);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(find(i) == i) cnt ++;
    }
    
    int ans = n - cnt;
    cout << m - ans << endl;







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