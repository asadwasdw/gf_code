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
vector<queue<int>>q(N);
int a[N], b[N];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        adj[y].push_back(x);
    }

    priority_queue<PII,vector<PII>,greater<PII>> pq;
    for(int i = 1; i <= n; i ++) {
        sort(adj[i].begin(), adj[i].end());
        for(auto t : adj[i]) q[i].push(t);
        q[i].push(INF);

        pq.push({q[i].front(), i});
        q[i].pop();
    }

    queue<PII> que;
    int now = 0;
    while(pq.size()) {
        auto [d, id] = pq.top(); pq.pop();
        // cout << d << " " << id << endl;
        
        if(que.size() == 0) {
            int f = min(d - now, b[id]);
            now += f, b[id] -= f;
            if(now >= d) {
                b[id] = a[id]; 
                pq.push({q[id].front(), id});
                q[id].pop();
            }
            else {
                que.push({d, id});
            }
        } else {
            auto [d2,id2] = que.front();
            int f = min(d2 - now, b[id]);
            now += f, b[id] -= f;
            if(now >= d2) {
                que.pop();
                b[id2] = a[id2];
                pq.push({q[id2].front(), id2});
                q[id2].pop();
            }
       
            if(b[id]) {
                pq.push({d, id});
            } else {
                que.push({d, id});
            }
        }
        // cout << now << " - "; for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
        // cout << que.size() << endl;
        // cout << endl;
    }
    // cout << now << endl;

    for(int i = 1; i <= n; i ++) {
        now += b[i];
        while(q[i].size()) q[i].pop();
        adj[i].clear();
    }
    cout << now << endl;

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
