#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);


void solve()
{
    int n, m, k; 
    cin >> n >> m >> k;
    vector dis(n + 1, INF);
    vector st(n + 1, 0);
    vector edg(n + 1, vector<PII>(0,{0,0}));

    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v, w});
        edg[v].push_back({u, w});
    }
   
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> s;

    q.push({0, 1});
    dis[1] = 0;
    for(int i = 2; i <= n; i ++) {
        s.push_back(i);
        dis[i] = (i|1)*k;
        q.push({dis[i], i});
    }


    while(q.size()) {
        auto[d, u] = q.top(); q.pop();
        if(st[u]) continue;
        st[u] = true;

        for(auto [v, w] : edg[u]) {
            if(dis[v] > d + w) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
        vector<int> ss;

        for(auto t : s) {
           if((t|u) == t) {
                if(k*t+d < dis[t]) {
                    q.push({k * t + d, t});
                    dis[t] = k * t + d;
                }
           }
           else ss.push_back(t);
        }

        swap(ss,s);
    }

    for(int i = 2; i <= n; i ++) cout << dis[i] << " \n"[i == n];


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