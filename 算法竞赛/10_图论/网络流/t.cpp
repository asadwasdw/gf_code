#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, I_MAX = b; i <= I_MAX; i ++)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
#define _rep(i, a, b) for(int i = a, I_MIN = b; i >= I_MIN; i --)
#define _mp(a, b) make_pair(a, b)
#define lowbit(x) ((x) & -(x))
#define endl '\n'
inline void Cout(char c) {
	if(c == endl) cout << "   000-----------000\n";
	else cout << "  " << c << c << c << "  ";
}
const string SX = "  XXX  ", SY = "  YYY  ", FG = "   0---------------0\n";
const int N = 2009, M = 1000009, mod = 998244353;

int n, m;
int f[N][N];
bool vis[N][N];

int ask(int l, int r) {
	if(l > r) return 0;
	if(vis[l][r]) return f[l][r];
	vis[l][r] = true;
	set<int> se;
	_for(i, l, r) {
		if(i * m >= r) se.insert(ask(l, i - 1));
	}
	int ans = 0;
	while(se.find(ans) != se.end()) ans ++;
	return f[l][r] = ans;
}
void solved() {
	n = ;  m = 3;
	_for(i, 0, n) cout << i << '\t';  cout << endl;
	_for(l, 1, n) {
		cout << l << '\t';
		_for(r, 1, n) {
			cout << ask(l, r) << '\t';
		} cout << endl;
	}
}

int main() {
	FIO
	bool ak = false;
	 solved();
	return 0;
}