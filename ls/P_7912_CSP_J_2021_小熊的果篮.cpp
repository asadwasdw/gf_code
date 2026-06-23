#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10; 
typedef pair<int,int> PII;
int n, m;

int a[N];

void solve() {
	
	int n;
	cin >> n;
	set<int> s[2];
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		a[i] = x;
		s[x].insert(i);
	}
	
	while(s[0].size() && s[1].size()) {
		int mn = min(*s[0].begin(), *s[1].begin());
		int t = a[mn];
		cout << mn << " ";
		s[t].erase(mn);
		while(s[t^1].size() && s[t^1].lower_bound(mn) != s[t^1].end()) {
			mn = *s[t^1].lower_bound(mn);
			t ^= 1;
			cout << mn << " ";
			s[t].erase(mn);
		}
		cout << endl; 
	}
	
	for(auto v : s[0]) cout << v << endl;
	for(auto v : s[1]) cout << v << endl; 
//	cout << s[0].size() << " " << s[1].size() << endl;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
	
	return 0;
} 