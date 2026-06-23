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



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, 0), b(n + 2, 0), c(n + 2, 0);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    b[1] = a[1];

    for(int i = 2; i <= n; i ++) {
        b[i] = min({a[i], b[i - 1] + 1});
    }

    b[n] = min(b[n], a[n]);

    for(int i = n - 1; i >= 1; i --) {
        b[i] = min({b[i], b[i + 1] + 1});
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += (a[i] - b[i]);
    }
    cout << ans << endl;
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
    return 0;
}