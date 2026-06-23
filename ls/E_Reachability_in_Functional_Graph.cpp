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

//vector<vector<int>>edg(N);
int n,m;
int a[N];

int f[N];
int d[N];
int num[N];
int dep[N];

int dfs(int u) {
    if(dep[u]) return dep[u];
    if(d[u]) return 0;
    return dep[u] = (dfs(f[u]) + 1);
}

int fa[N];
int find(int x) {
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void solve()
{
    int n;
    cin >> n;
    for(int i =1; i <= n; i ++) {
        fa[i] = i;
        cin >> f[i];
        d[f[i]]++;
    }

    queue<int>q;
    for(int i = 1;i <= n; i++){
        if(d[i] == 0) {
            q.push(i);
        }
    }
    
    

    // for(int i = 1; i <= n; i ++) {
    //     cout << dep[i] << " " << d[i] << endl;
    // }

    while(q.size()){
        int u = q.front(); q.pop();
        int v = f[u];
        if( --d[v] == 0) q.push(v);
    }


for(int i = 1; i <= n;i ++) dfs(i);


    for(int i = 1; i <= n; i ++) {
        int u = i, v = f[i];
        u = find(u), v = find(v);
        if(u == v) continue;
        d[v] += d[u];
        fa[u] = v;
    }



    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += dep[i] + d[find(i)];
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
}