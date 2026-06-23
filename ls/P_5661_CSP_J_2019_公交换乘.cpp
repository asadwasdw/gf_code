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
    int n;
    cin >> n;
    int ans = 0;
    priority_queue<PII,vector<PII>, greater<PII>> q;
    for(int i = 1; i <= n; i ++) {
        int op, p, t;
        cin >> op >> p >> t;
        if(op == 0) {
            ans += p;
            q.push({t, p});
        } else {
            while(q.size() && q.top().first < t - 45) q.pop();
            bool ky = false;
            vector<PII> v;
            while(q.size()) {
                auto [x, y] = q.top();
                // cout << x << " " << y << endl;
                q.pop();
                if(y >= p) {
                    ky = true;
                    break;
                } else {
                    v.push_back({x, y});
                }
            }
            if(!ky) ans += p;
            for(auto ve : v) {
                q.push(ve);
            }
        }
        // cout << i << " " << ans << endl;
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
} 