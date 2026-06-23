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

ll a[N];
void solve()
{

    for (int i = 2; i <= 11; i++) {
        a[1 << i] = 2 * ((1ll << (i - 1)) + a[1 << (i - 1)]);
    }    
    ll ans = 0;
    for (int i = 0; i < 16; i++) {
        int x; cin >> x;
        if (x != 0 && x != 2) {
            ans += a[x];
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