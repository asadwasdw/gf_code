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

//vector<vector<int>>adj(N);


int color[N];

void solve()
{
    int m, k, n;
    cin >> n >> k >> m;
    priority_queue<PII> q;
    for(int i = 1; i <= n; i ++) {
        int c, v;
        cin >> c >> v;
        q.push({v, c});
    }
    ll ans = 0, cnt = 0;
    while(k) {
        if(k + cnt > m) {

        } else {
            while(q.size() && color[q.top().second]) q.pop();
        }
        auto [v, c] = q.top(); q.pop();
        ans += v;
        if(color[c] == 0) cnt ++;
        color[c] ++;
        k --;

    }

    cout << ans << endl;
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