#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
typedef long double db;
struct wt{
    int t;
    db p;
    int id;
    wt(){}
    wt(int t1,db p1,int id1){
        t = t1;
        p = p1;
        id = id1;
    }
}q[N];
db ans[N];

db dp[100][3000];
bool cmp (wt a, wt b) {
    return a.t < b.t;
}

void solve()
{
    int n, K, T;
    cin >> n >> K >> T;
    for(int i = 1; i <= n; i++) {
        int t1;
        db p1;
        cin >> p1 >> t1;
        q[i] = {t1, p1, i};
    }
    sort(q + 1, q + n + 1,cmp);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        // auto [t, p, id] = q[i];
        int t = q[i].t;
        int p = q[i].p;
        int id = q[i].id;
        for(int k = K-1; ~k ; k--) {
            for(int t1 = 0; t1 + t <= T; t1 ++) {
                db P =   (K - k - 1)/(n - i - 1);
                ans[id] += dp[k][t] * p;
                dp[k + 1][t1 + t] += dp[k][t1] * p * P ; 
                dp[k + 1][t1] += dp[k][t1] * (1-p) * P; 
                dp[k][t1] = dp[k][t1] * (1-P); 
            }
        }
    }

    for(int i = 1; i <= n;i ++) cout << ans[i] << '\n';







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