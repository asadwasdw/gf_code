#include<bits/stdc++.h>
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
struct edg{
    int u,v,w;
}e[N];
map<PII,int>st;
int f[N];
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        f[i] = i;
    }
    for(int i = 1; i < n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        int fx = find(x);
        int fy = find(y);
        st[{fy,fx}] = st[{fx,fy}] = z;
        f[fx] = fy;
        ans += z;
    }

    while(m --) {
        int u, v, w;
        cin >> u >> v >> w;

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