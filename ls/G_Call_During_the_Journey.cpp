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

int h[N], ne[N], e[N], l1[N], l2[N], idx;

void add(int a, int b, int c, int d) {
    e[idx] = b, l1[idx] = c, l2[idx] = d,ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, l1[idx] = c, l2[idx] = d,ne[idx] = h[b], h[b] = idx ++;
}

bool check(int l1, int r1, int l2, int r2) {
    int l = max(l1, l2), r = min(r1, r2);
    return l < r;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    

    for(int i = 1; i <= m; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
    }


    vector<int> dis(n + 1, INF);
    vector<int> st(n + 1, false);
        dis[n] = t0;

    priority_queue<PII> q;
    q.push({t0, n});

    while(q.size()) {
        auto [tu, u] = q.top(); q.pop();
        if(st[u]) continue;
        st[u] = true;
        dis[u] = tu;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            int tv = tu - l1[i]; // 直接开车
            if(check(t1, t2, tv, tu)) { //有冲突
                tv = max(t1 - l1[i], (int)tu - l2[i]); 
            }
            q.push({tv, v});
        } 
    } 

    cout << max(-1ll, dis[1]) << endl;







    // cout << n << endl;

    for(int i = 1; i <= n; i ++) {
        // cerr << h[i] << endl;
        h[i] = -1;
    }
    // idx = 0;

}


signed main()
{
    memset(h, -1, sizeof h);
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