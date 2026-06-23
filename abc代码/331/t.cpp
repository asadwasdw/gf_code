#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1000010;

int n, q;
string s;
int p[] = {
	1000000007, 
	1000000009, 
	1000000021, 
	1000000033, 
	1000000087
};
struct T {
	ull h1, h2, pw;
};
struct node {
	T h[5];
	node() {
		for(int i = 0; i < 1; i++) {
			h[i] = {0, 0, 1};
		}
	}
	node(char c) {
		for(int i = 0; i < 1; i++) {
			h[i] = {(ull)c, (ull)c, (ull)p[i]};
		}
	}
}tr[N * 4];

void merge(node &root, node &le, node &ri) {
	for(int i = 0; i < 1; i++) {
		root.h[i].h1 = le.h[i].h1 * ri.h[i].pw + ri.h[i].h1;
		root.h[i].h2 = le.h[i].h2 + ri.h[i].h2 * le.h[i].pw;
		root.h[i].pw = le.h[i].pw * ri.h[i].pw;
	}	
}

void pushup(int u) {
	merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
	tr[u] = node(s[r]);
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int x, char c) {
	if(x == l && x == r) {
		tr[u] = node(c);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) update(u << 1, l, mid, x, c);
	else update(u << 1 | 1, mid + 1, r, x, c);
	pushup(u);
}

node query(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R) return tr[u];
	int mid = (l + r) >> 1;
	if(R <= mid) return query(u << 1, l, mid, L, R);
	if(L > mid) return query(u << 1 | 1, mid + 1, r, L, R);
	node res;
	node le = query(u << 1, l, mid, L, R);
	node ri = query(u << 1 | 1, mid + 1, r, L, R);
	merge(res, le, ri);
	return res;
}

void solve() {
	cin >> n >> q >> s;
	s = " " + s;
	build(1, 1, n);
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int x;
			char c[2];
			cin >> x >> c;
			update(1, 1, n, x, *c);
		} else {
			int l, r;
			cin >> l >> r;
			node res = query(1, 1, n, l, r);
			int flag = 1;
			for(int i = 0; i < 5; i++) flag &= res.h[i].h1 == res.h[i].h2;
			cout << (flag ? "Yes\n" : "No\n");
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--) solve();
	return 0;
}