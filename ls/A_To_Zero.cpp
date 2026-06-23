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


void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    // if(k % 2 == 0) {
    //     if(n % 2) {
    //         ans ++;
    //         n -= k - 1;
    //     }

    //     int cnt = n / k;
    //     n -= cnt * k;
    //     ans += cnt;
    //     if(n) ans ++;
    // }

    if(n % 2) {
        n -= k;
        ans ++;
    }

    k --;
    ll cnt = n / k;
    n -= cnt * k;
    ans += cnt;
    if(n) ans ++;

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
}