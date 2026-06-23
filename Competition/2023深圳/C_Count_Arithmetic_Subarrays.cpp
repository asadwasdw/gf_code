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

ll a[N];
ll b[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    ll ans = 0;

    for(int l = 2; l <= n; l ++) {
        int r = l;
        while(r + 1 <= n && b[r + 1] == b[r]) r ++;
        ll cnt = r - l + 2;
        // cout << l << " " << r << " " << cnt << endl;
        ans += cnt * (cnt - 1) / 2;
        l = r;
    }
    cout << ans + n<< endl;







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