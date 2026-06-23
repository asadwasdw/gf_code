#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);


void solve()
{
    int sum = 0;
    int n,x;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> x; sum += x;
    }
    int ans = 0;
    if(sum%n == 0) {
        cout << sum/n << endl;
        return;
    }
    for(int i = 30;i >= 0; i --) {
        int t = (1ll << i);
        if(sum >= (t) * n ) {
            sum -= t * n;
            ans += t;
        }
        else if(sum > (t - 1) * n) {
            sum -= min(n,sum/t) * t;
            ans += t;
        }
        // cout << i << " " << ans  << " " << (2 * t - 1) * n  << " " << sum << endl;
    }

    // if(sum) ans ++;
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