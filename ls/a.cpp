#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 305;
int n, h, dp[N][N][N]; // [1,i]
int a[N], v[N], w[N], ans = 1e9;
signed main() {
	cin >> n >> h;
	for(int i = 1;i <= n; ++i) scanf("%lld", &a[i]);
	for(int i = 1;i < n; ++i) scanf("%lld %lld", &v[i], &w[i]);
	memset(dp, 0x3f, sizeof dp);
	dp[0][h][0] = 0;
	for(int i = 1;i <= n; ++i) {
		int dis = a[i] - a[i - 1];
		for(int j = 0;j <= h; ++j)
	 		for(int k = 0;k <= h; ++k) {
	 			int nj = j - dis, nk = k + dis;
	 			if(nj < 0 or nk > h) continue ;
	 			
				dp[i][nj][nk] = min(dp[i - 1][j][k], dp[i][nj][nk]); // never here
                
				dp[i][min(h, nj + w[i])][nk] = min(dp[i][min(h, nj + w[i])][nk], dp[i - 1][j][k] + v[i]);
				// first 
                
				dp[i][nj][max(0, nk - w[i])] = min(dp[i][nj][max(0, nk - w[i])], dp[i - 1][j][k] + v[i]);
				// second here
			}
	}
	
	for(int i = 0;i <= h; ++i) 
		for(int j = 0;j <= h; ++j)
			if(j <= i) ans = min(ans, dp[n][i][j]); 

	if(ans == 1e18) puts("-1");
	else cout << ans; 
    return 0;
}