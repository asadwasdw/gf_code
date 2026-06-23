#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int dp[N],pre[N];
int fac[N];
int infac[N];

int qmi(int a,int b) {
    int res = 1;
    while(b) {
        if(b&1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    fac[0] = 1; 
    pre[0] = 1; 
    pre[1] = 2; 
    dp[1]=1;
    for(int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    infac[n] = qmi(fac[n],mod-2); 
    for(int i = n - 1; i ; i--) {
        infac[i] = infac[i + 1] * (i+1) % mod;
    }

    for(int i = 2; i <= n; i ++) {
        if(i <= k) {
            dp[i] = fac[i - 1] * pre[i - 1] % mod;
        }
        else {
            dp[i] = (pre[i - 1] - pre[i - k - 1] + mod) % mod * fac[i - 1] % mod; 
        }
        pre[i] = pre[i - 1] + dp[i] * infac[i] % mod;
        pre[i] %= mod;
    }
    cout << dp[n] << '\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}