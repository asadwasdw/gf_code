#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 507, mod = 998244353;


int a[N], sum[N], dp[N][N], c[N][N];
int n;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	c[0][0] = 1;
	for(int i = 1; i <= sum[n]; i++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j++) 
			c[i][j] = (c[i][j] + c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}

	dp[0][0] = 1;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j <= sum[i]; j++) if (dp[i][j]) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            //全放在后面，


			for (int k = j + 1; k < sum[i + 1]; k++) { 
				int lb = max(0, a[i + 1] - (k - j)); 
                // 不放在后面的，最多只能放(k-j)个,超过就会使（新的最后一个长度为 2 的下降子序列靠前前的那个数字的位置是>k) 
                // 那么放在后面的，最少就是（a[i + 1] - (k - j)）
				int ub = min(a[i + 1] - 1, sum[i + 1] - k - 1);
                // 至少留一个去更新
                // (k + 1 + x <= sum[i - 1]) => (x <= sum[i - 1] - k - 1)
				for(int x = lb; x <= ub; x++) 
					dp[i + 1][k] = (dp[i+1][k] + (1ll * dp[i][j] * c[k - j - 1][a[i + 1] - x - 1] % mod)) % mod;

                // （j - k] 有(k - j)个位置，第k个位置一定要是（i + 1） 还有[k - j - 1]个位置要放[a[i] + 1 - x - 1]个(i ) 
			}
		}

	int ans = 0;
	for(int i = 0; i <= sum[n]; i++) ans = (ans + dp[n][i]) % mod;
	cout<<ans<<'\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--)
		solve();
	return 0;
}
