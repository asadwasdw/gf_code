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

ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b & 1)res = res * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return res;
}

void solve()
{
    ll n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        sum += x;
    }

    // cout << 11 * qmi(4, mod - 2, mod) % mod << endl;
    // cout << " as";
    cout << 1ll * sum % mod * qmi(n, mod - 2, mod) % mod << endl;








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