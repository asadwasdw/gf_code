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
PII v[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i].first >> v[i].second;

    sort(v + 1, v + n + 1,[&](PII a, PII b) {
        return a.first < b.first;
    });
    int i = n;
    ll ans = 0;
    for(int l = m, r = m + 1; l >= 1; l --) {
        while(i && v[i].first == l) {
            r = min(r, v[i].second);
            i --;
        }
        ans += r - l;
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