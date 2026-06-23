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

ll qmi(ll a, ll b,ll c) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (__int128)res * a % c;
        a = (__int128)a * a % c;
        b >>= 1;
    }
    return res;
}



bool is_prime(ll x) {
    if(x == 1) return false;
    if(x <= 3) return true;
    if(x % 2 == 0) return false;

    ll A[] = {2, 325, 9375, 450775, 9780504, 1795265022}, d = x - 1, r = 0;

    while(d % 2 == 0) d /= 2, ++r;
    
    for(auto a : A) {
        ll v = qmi(a, d, x);
        
        if(v <= 1 || v == x - 1) continue;

        for(int i = 0; i < r; i ++) {
            v = (__int128)v * v % x;
            if(v == x - 1 && i != r - 1) {
                v = 1;
                break;
            }
            if(v == 1) return false;
        }
        if(v != 1) return false;
    }
    return true;
}

int dp[N][4];
int a[N];
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i ++) {
        if(is_prime(a[i] + a[i - 1])) {
            dp[i][0] = min(dp[i][0] , dp[i - 1][0]);
        }
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;


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