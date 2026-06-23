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

int a[N][7];
int dp[N][7];
int cnt[N];

PII b[N];


ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1; 
    }
    return res;
}

ll inv(ll t) {
    return qmi(t, mod - 2, mod);
}

void solve()
{

    int n; cin >> n;
    int m = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= 6; j ++) {
            cin >> a[i][j]; 
            b[++ m] = {a[i][j], i};
        }
    }

    sort(b + 1, b + m + 1,[&](PII a, PII b){
        return a.first < b.first;
    });

    ll inv6 = qmi(6, mod - 2, mod);

    ll p = 1;
    int cnt0 = n;
    ll ans = 0;
    for(int i = 1; i <= m; i ++) {
        auto [x, y] = b[i];
        cnt[y] ++;
        if(cnt[y] == 1) {
            cnt0--;
            p = p * inv6 % mod;
        } else {
            p = p * inv(cnt[y] - 1) % mod * 6 % mod;
            p = p * cnt[y] % mod * inv6 % mod;
        }
    

        if(!cnt0) {
            // cout << x << " " <<  p << endl;
            ans += x * inv6 % mod * p % mod * inv(cnt[y]) % mod * 6 % mod;
        }

        ans %= mod;
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
}