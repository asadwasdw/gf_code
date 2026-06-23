#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<char,int>PCI;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

string s;
stack<int> t;
ll ans = 0;
ll num[N];
int f[N];
int lst[N];
void dfs(int u) {
    for(auto v : adj[u]) {
        if(s[v] == ')' && t.size()) {
            int tmp = t.top(); t.pop();

            lst[v] = 1 + lst[f[tmp]];
            num[v] = num[u] + lst[v];

            dfs(v);
            t.push(tmp);
        } else if(s[v] == '(') {
            t.push(v);
            num[v] = num[u];
            dfs(v);
            t.pop();
        } else {
            num[v] = num[u];
            dfs(v);
        }
    }
} 

void solve()
{
    int n;
    cin >> n;
    cin >> s;

    s = " " + s;

    for(int i = 2; i <= n; i ++) {
        cin >> f[i];
        adj[f[i]].push_back(i);
    }
    if(s[1] == '(') t.push(1);
    dfs(1);

    for(int i = 1; i <= n; i ++) ans ^= i * num[i];

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