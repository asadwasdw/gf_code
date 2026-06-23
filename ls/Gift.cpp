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

vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j ++) {
            int x; 
            cin >> x;
            adj[x].push_back(i);
        }
    }

    for(int i = 1; i <= n; i ++) {
        sort(adj[i].begin(), adj[i].end());
        cout << adj[i].size() << " ";
        for(auto t : adj[i]) cout << t << " ";
        cout << endl;
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
    return 0;
}