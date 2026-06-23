#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
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
void init(){
    //求阶乘
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    //求逆元
    Inv[N-1]=qmi(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--){
        Inv[i]=Inv[i+1]*(i+1)%mod;
    }
}
 
ll C(int n,int m){
    if(n <= 0) return 0;
    if(m>n){
        return 0;
    }
    if(m==0)
        return 1;
    return fac[n]%mod*Inv[m]%mod*Inv[n-m]%mod;
}


void solve()
{
    ll sum = 0;
    vector num(30, 0ll);
    for(int i = 1; i <= 26; i ++) {
		cin >> num[i];
		sum += num[i];
    }

	ll odd = (sum + 1) / 2;
	ll even = sum - odd;

	vector dp(sum + 10, 0ll);
	dp[0] = 1;

	for(int i = 1; i <= 26; i ++) {
		if(num[i] == 0) continue;
		for(int j = sum; j >= num[i]; j --) {
			dp[j] = (dp[j] + dp[j - num[i]]) % mod;
		}
	}

	ll ans = dp[odd]; // 先分组， 26个字母使用奇数个位置有多少的方案数
	// 分好组之后，对于每个字母，就是高中数学的排列问题，n!/(c1! * c2! ...)
	// cout << ans << endl;
	ans = ans * fac[odd] % mod * fac[even] % mod; 

	for(int i = 1; i <= 26; i ++) {
		ans = (ans * Inv[num[i]]) % mod;
	}
	cout << ans << endl;
}


signed main()
{
    init();
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