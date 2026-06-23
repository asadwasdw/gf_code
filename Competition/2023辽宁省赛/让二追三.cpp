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

using i64 = long long;
constexpr i64 P = 1e9 + 7;

i64 qpow(i64 a, i64 b){
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}
void solve()
{

    i64 a, b, n; cin >> a >> b >> n;
    if (n <= 4) {
        cout << 0 << "\n";
        return;
    }
    i64 q = a * qpow(b, P - 2) % P;
    i64 ans = q * q % P * q % P * (1 - q + P) % P * (1 - q + P) % P;
    ans = ans * (n - 4) % P;
    cout << ans << "\n";

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