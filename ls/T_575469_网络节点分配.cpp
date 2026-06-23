#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod; 
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}


int d[N];
int n;

void solve()
{
    
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int x; cin >> x;
        int u = x, v = i + 1;
        d[u] ++, d[v] ++;
    }


    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(d[i] == 1) continue;
        ans += (qmi(2, d[i]) - 2 + mod) % mod;
        ans %= mod;

        
    }

    cout << ans % mod << endl;


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