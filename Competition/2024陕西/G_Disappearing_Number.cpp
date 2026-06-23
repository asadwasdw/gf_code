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
ll n,m;
int a[N];
ll f[70][10][10];
vector<int> p;
ll dfs(int u, int x, int fx, int limit, int lead){
    if(u == -1)return fx;
    if(!limit && !lead && ~f[u][x][fx])return f[u][x][fx];
    int up = limit ? p[u] : 9;
    ll res = 0;
    for(int i=0; i<=up; ++i){
        if(lead && i == 0){
            res += dfs(u-1, x, 0, limit && i == p[u], true);
        }
        else{
            res += dfs(u-1, x, fx | i == x, limit && i == p[u], false);
        }
    }
    if(!limit && !lead)f[u][x][fx] = res;
    return res;
}


void solve()
{
    cin >> n >> m;
    ll nn = n;
    p.clear();
    while(n)p.push_back(n%10), n/=10;
    ll ans = nn - dfs(p.size()-1, m, 0, true, true);
    // cout << ans << endl;
    cout << ans + 1 << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    memset(f, -1, sizeof f);
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}