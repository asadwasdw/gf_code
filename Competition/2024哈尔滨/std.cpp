#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);
int a[N];
int n, m; 
int ans = 0;
void dfs(int x, vector<int> st) {
    
    ans = max(ans,x);
    for(auto t : adj[x]) {
        st[t] = a[t];
    }

    for(int i = 1; i <= n; i ++) {
        if(st[i]) {
            st[i] --;
            dfs(x + 1, st);
            st[i] ++;
        }
    }
}

void solve()
{
    cin >> n >> m;
    vector<int> st(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        st[i] = a[i];
    }
    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    dfs(0, st);
    cout << ans << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}