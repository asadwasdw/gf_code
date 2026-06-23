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
const int M = 1010;
char d[M][M];
int rd[N];

void solve()
{

    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> d[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            if(d[i][j] == '1') {
                adj[i].push_back(j);
                rd[j] ++;
            } else {
                adj[j].push_back(i);
                rd[i] ++;
            }
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i ++) {
        if(rd[i]) continue;
        q.push(i);
    }
    vector<int> ans;
    while(q.size()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(auto v : adj[u]) {
            rd[v] --;
            if(rd[v] == 0) {
                q.push(v);
            }
        }
    }
    for(auto t : ans) cout << t << " "; cout << endl;
    for(int i = 1; i <= n; i ++) adj[i].clear();
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