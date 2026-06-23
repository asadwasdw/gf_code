#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5 + 10;
const int mod = 1;
int T, n, k;
string s;
void solve(){
	scanf("%d%d", &n, &k);
	cin >> s;
	vector <int> cnt(26);
	for (char c : s)
		cnt[c - 'a']++;
	int cntP = 0, cntO = 0;
	for (int x : cnt){
		cntP += x / 2;  
		cntO += x % 2;  
	}
	int ans = 2 * (cntP / k);
	cntO += 2 * (cntP % k);
	if (cntO >= k) ans++;  
	cout << ans << "\n"; 
}
int main(){
	cin >> T;
	while(T--)
		solve();
	return 0;
}

  	  	 			           	 	  	 	 	