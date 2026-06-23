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
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> a(n + 1, 0);
    while(b --) {
        int x; cin >> x;
        a[x] = 1;
    }  

    for(int i = 1; i <= n; i ++) {
        // cout << a[i] << " \n"[i == n];
        a[i] += a[i - 1];
    }

    int ans = INF;
    for(int l = 1; l + k - 1 <= n; l ++) {
        int r = l + k - 1;
        ans = min(ans, a[r] - a[l - 1]);
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