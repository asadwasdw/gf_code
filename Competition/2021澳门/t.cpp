#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
#define int long long
#define ll long long
 
const int N = 1e6 + 6, INF = 1e18;
ll dp[N][2], p[N], lxt[N], rxt[N];
int a[N], n, k;
 
struct Node {
	int l, r;
    ll minn;
}tr[N * 4];
 
void pushup(Node& u, Node& l, Node& r)
{
	u.minn = min(l.minn, r.minn);
}
 
void pushup(int u)
{
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
 
void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u] = { l, r, a[l] };
		return;
	}
	tr[u].l = l, tr[u].r = r;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
 
void update(int u, int x, int c)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		tr[u].minn = c;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	x <= mid ? update(u << 1, x, c) : update(u << 1 | 1, x, c);
	pushup(u);
}
 
int query(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].minn;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	int res = INF;
	if (l <= mid) res = query(u << 1, l, r);
	if (r > mid) res = min(res, query(u << 1 | 1, l, r));
	return res;
}
 
int query_not(int l, int r)
{
	if (l < 1) l += n;
	if (r > n) r -= n;
 
	if (l <= r)
	{
		int res = INF;
		if (l != 1) res = query(1, 1, l - 1);
		if (r != n) res = min(query(1, r + 1, n), res);
		return res;
	}
	else
	{
		return query(1, r + 1, l - 1);
	}
}
 
int ask(int p1, int p2)
{
	if (p1 < 1) p1 += n;
	if (p1 > n) p1 -= n;
	return min(n - p2 + p1, min(abs(p1 - p2), p2 + n - p1));
}
 
void solve() {
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		p[a[i]] = i;
	}
	if (k == n)
	{
		printf("0\n");
		return;
	}
	build(1, 1, n);
	int t = query_not(1, k);
	dp[t][0] = min(p[t] - 1, n - p[t] + 1), dp[t][1] = min(abs(k - p[t]), n - p[t] + k);
	for (int i = 1; i <= n; i++)
	{
		if (i != t) dp[i][0] = dp[i][1] = INF;
		if (i < t)
		{
			update(1, p[i], INF);
		}
		else 
		{
			lxt[i] = query_not(p[i], p[i] + k - 1);
			rxt[i] = query_not(p[i] - k + 1, p[i]);
			update(1, p[i], INF);
		}

        cout << i << " " << lxt[i] << " " << rxt[i] << endl;
	}
	ll ans = INF;
	for (int i = t; i <= n; i++)
	{
		if (lxt[i] != INF)
		{
			ll u = lxt[i];
			dp[u][0] = min(dp[u][0], dp[i][0] + ask(p[i], p[u]));
			dp[u][1] = min(dp[u][1], dp[i][0] + ask(p[i] + k - 1, p[u]));
		}
		else
		{
			ans = min(ans, dp[i][0]);
		}
		if (rxt[i] != INF)
		{
			ll u = rxt[i];
			dp[u][0] = min(dp[u][0], dp[i][1] + ask(p[i] - k + 1, p[u]));
			dp[u][1] = min(dp[u][1], dp[i][1] + ask(p[i], p[u]));
		}
		else
		{
			ans = min(ans, dp[i][1]);
		}
	}
	printf("%lld\n", ans);
	return;
}
 
signed main() {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%lld", &t);
	while (t--) solve();
	return 0;
}