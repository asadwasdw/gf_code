#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
double d[N], p[N];
double ans = INF;
double d1, c, d2;
int n;
void dfs(int x, double res, double s) {
    if(x == n + 1) {
        ans = min(res, ans);
        return;
    }

    for(int y = x + 1; y <= n + 1; y ++) {
        double t = d[y] - d[x];
        double w = t / d2;
        if(w > c) continue;

        if(w > s)dfs(y, res + p[x] * (w - s), 0);
        if(w <= s)dfs(y, res, s - w);
        dfs(y, res + p[x] * (c - s), c - w);
    }
  
}

void solve()
{
    cin >> d1 >> c >> d2 >> p[0] >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> d[i] >> p[i];
    }
    d[n + 1] = d1;
    dfs(0, 0, 0);
    if(ans >= INF) cout <<"No Solution";
    else printf("%.2lf",ans);
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(2) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}