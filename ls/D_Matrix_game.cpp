#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

ll Inv[N], fac[N];  //分别表示逆元和阶乘
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

 
ll C(int n,int m){

    
    if(m>n){
        return 0;
    }
    if(m==0)
        return 1;

    ll res = 1;
    for (int i = 1, j = n; i <= m; i++, j--) {
        res = res * j % mod;
        res = res * qmi(i, mod - 2) % mod;
    }
    return res;
}

ll lucas(ll a, ll b)
{
  if (a < mod && b < mod)
    return C(a, b);
  return (ll)C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;
}


void solve()
{

    ll a, b, k;
    cin >> a >> b >> k;
    ll n = ((a - 1) * k + 1) % mod;
    ll m = k * lucas(n, a)%mod * (b - 1)%mod + 1;

    cout << n << " " << m % mod << endl; 
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