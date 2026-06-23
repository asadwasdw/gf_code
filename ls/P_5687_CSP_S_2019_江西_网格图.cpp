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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
    }


    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + m + 1);

    // for(int i = 0; i <= n; i ++) cout << a[i] << endl;
    // for(int i = 0; i <= n; i ++) cout << b[i] << endl;

    ll ans = 0;
    int l = 2, r = 2;

    
    while(l <= n || r <= m) {
        if(a[l] < b[r]) {
            ans += a[l++];
        } else {
            ans += b[r++];
        }
    }
    for(int i = 1; i <= n; i ++)  ans += a[i] * (m - i);
    for(int i = 1; i <= m; i ++)  ans += b[i] * (n - i);
    

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