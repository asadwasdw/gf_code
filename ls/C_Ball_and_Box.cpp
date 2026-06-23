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

struct xz {
    int v, p;
    // bool st = false;
}w[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    long double xjb = 0;
    int V, P;
    for(int i = 1; i <= n; i ++) {
        cin >> w[i].v >> w[i].p;
    }

    if(m > n) {
        cout << '0' << endl;
        return;
    }

    sort(w + 1, w + n + 1, [&](xz a, xz b){
        return a.p*b.v > b.p*a.v;
    });

    for(int i = 1; i <= n; i ++) {
        cout << w[i].v << " " << w[i].p << endl;
    }

    int ans = 0;
    int res = 0;

    for(int i = 1; i <= m; i ++) {
        res += w[i].p - 1;
        w[i].v --;
        ans = max(ans, res);
    }

    sort(w + 1, w + n + 1, [&](xz a, xz b){
        return a.v < b.v;
    });

    for(int i = 1; i <= n; i ++) {
        
    }







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