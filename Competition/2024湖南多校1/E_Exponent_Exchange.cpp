#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int a[N];
void solve()
{
    int b,p;
    cin >> b >> p;
    int m = b * p;
    vector<array<int,2>> g(m + 1,array<int,2>{0,0});
    for(int i = p; i; i--) cin >> a[i];
    int ans = INF;
    for(int i = 1; i <= p; i ++) {
        vector<array<int,2>> f(m + 1,array<int,2>{m,m});
        int v = b - a[i] - 1;
        if(i == 1) v ++;
        
        for(int j = 0; j <= m; j ++) {
            if(j >= a[i]) f[j][0] = min(f[j][0], g[j - a[i]][0]);
            if(j >= a[i] + 1) f[j][0] = min(f[j][0], g[j - a[i] - 1][1]);

            f[j][1] = min(g[j][0] + v + 1, g[j][1] + v);
        }

        g.swap(f);
    }

    for(int j = 0; j <= m; j ++) {
        for(int i = 0; i < 2; i ++) {
            ans = min(ans, max(j,g[j][i]));
        }
    }
    cout << ans << '\n';

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