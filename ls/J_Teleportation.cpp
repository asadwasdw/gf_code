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

//vector<vector<int>>adj(N);


void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 10, 0);
    vector<int> dis(n + 10, INF);
    vector<int> st(n + 10, 0);
    dis[0] = 0;

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        // a[i] = i ;
    }

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0, 0});
    int cnt = 0;
    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
        // cout << u << " " << d << endl;
        if(st[u]) continue;
        st[u] = 1;
        if(u == x) {
            // cerr << cnt << endl;
            cout << d;
            return;
        }
        int cnt = 0;
        for(int i = 0; i + d < n + 10; i ++ ) {
            // cnt ++ ;
            int v = (u + i + a[u])%n;
            int w = d + i + 1;  
            // cout << v << " " << w << endl;
            if(dis[v] > w) {
                dis[v] = w;
                q.push({dis[v], v});
            } else {
                cnt ++;
                if(cnt >= 0) break;
            }
        }
    }
    // cout << 's' << endl;






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