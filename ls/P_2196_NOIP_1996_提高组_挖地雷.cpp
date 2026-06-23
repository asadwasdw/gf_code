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

int adj[25][25];
int a[N];
int ans = 0;
vector<int> anst;
int n;

void dfs(int u, int sum, vector<int> t) {
    if(sum > ans) {
        ans = sum;
        anst = t;
    }

    for(int v = u + 1; v <= n; v ++) {
        if(!adj[u][v]) continue;
        vector<int> tt = t;
        tt[v] = 1;
        dfs(v, sum + a[v], tt);
    }
    

}

void solve()
{
    
    cin >> n;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            cin >> adj[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        vector<int> t(n + 1, 0);
        t[i] = 1;
        dfs(i, a[i], t);
    }

    for(int i = 1; i <= n; i ++ ) {
        if(anst[i]) cout << i << " ";
    }
    cout << endl;
    cout << ans << endl;





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