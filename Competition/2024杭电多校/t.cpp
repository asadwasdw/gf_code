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


map<vector<int>, int> mp;
int cnt = 0;

int dfs(int u) {
    vector<int> res;
    
}

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    get(1);







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