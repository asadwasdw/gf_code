#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e2 + 9, M = 25e4 + 9;
int a[N], b[(1 << 20) + 9];

int main() {
	
	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	
	ll ans = 0;
	for(int i = 0; i <= n / a; i ++) {
		int yu = n - i * a;
		ans = max(ans, (ll)i * x + (ll)yu / b * y + yu % b);
	}
	
	cout << ans;
	
	return 0;
}