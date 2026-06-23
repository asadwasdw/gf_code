#include<bits/stdc++.h>
using namespace std;
const int A = 26;
const int N = 200022;
int dp[N][12];
char s[N], t[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s%s", s, t);
	dp[0][m - 1] = s[0] == t[0];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(dp[i][j] == false) {
				continue;
			}
			if(i + m < n && s[i + 1] == t[0]) {
				dp[i + 1][m - 1] = true;
			}
			if(j > 0 && s[i + 1] == t[m - j]) {
				dp[i + 1][j - 1] = true;
			}
			if(j == 0) {
				for(int k = 0; k < m; k++) {
					if(s[i + 1] == t[k]) {
						dp[i + 1][m - k - 1] = true;
					}
				}
			}
		
		}
	}
	printf("%s\n", dp[n - 1][0] ? "Yes" : "No");
}
