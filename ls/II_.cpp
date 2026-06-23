#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; ++i)cin >> a[i];
    vector<int> dist(n, INF);
    dist[0] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({dist[0], 0});
    while(q.size()){
        auto [_, u] = q.top();q.pop();
        int nx = (u+1) % n;
        if(dist[nx] > dist[u] + 1){
            dist[nx] = dist[u] + 1;
            q.push({dist[nx], nx});
        }
        nx = (u + a[u]) % n;
        if(dist[nx] > dist[u] + 1){
            dist[nx] = dist[u] + 1;
            q.push({dist[nx], nx});
        }
    }
    cout << dist[x] << endl;





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