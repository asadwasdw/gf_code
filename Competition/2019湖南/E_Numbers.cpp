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
ll n, ans;
string s; 
bool vis[100];
void dfs(int u) {
    // cout << u << endl;
    if(u == n) {
        ans ++;
        return;
    }
    int t = s[u] - '0';
    if(!vis[t]) {
        vis[t] = true;
        dfs(u + 1);
        vis[t] = false;
    }

    if(u + 1 < n && s[u] != '0') {
        t = t * 10 + s[u + 1] - '0';
        if(!vis[t]) {
            vis[t] = true;
            dfs(u + 2);
            vis[t] = false;
        }
    }
}

void solve()
{
    while(cin >> s) {
        n = s.size();
        ans = 0;
        dfs(0);
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