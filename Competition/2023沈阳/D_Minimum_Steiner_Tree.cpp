#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);

int d[N];
bool isk[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i ++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        d[a] ++, d[b] ++;
    }
    for(int i = 1; i <= k; i ++) {
        int x; cin >> x;
        isk[x] = true;
    }
    queue<int> q;

    for(int i = 1; i <= n; i ++) {
        if(d[i] == 1 && isk[i] == false) q.push(i);
    }

    while(q.size()) {
        n --;
        int u = q.front(); q.pop();
        // cout << u << endl;
        for(auto v : adj[u]) {
            d[v] --;
            if(d[v] == 1 && isk[v] == false) q.push(v);
        }
    }

    cout << n << endl;






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