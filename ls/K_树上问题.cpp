#include<cstdio>
#include<algorithm>
#define pa pair<int,int>
#define mp make_pair
using namespace std;
const int N = 200005;
struct Tree{ int u, v, du, dv; } T[N << 2];
struct Edge{ int to, nxt; } e[N << 1];
int head[N], dis[N], pos[N], Log[N], f[N][21], g[N << 1][21], tot, num, n, m;

bool cmp(int x,int y) {
	return dis[x] < dis[y];
}
int Min(int x,int y) { 
	return dis[x] < dis[y] ? x : y;
}
void add_edge(int u,int v) {
	++tot; e[tot].to = v; e[tot].nxt = head[u]; head[u] = tot;
}
void dfs(int u) {
	g[++num][0] = u; pos[u] = num;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == f[u][0]) continue;
		f[v][0] = u, dis[v] = dis[u] + 1, g[++num][0] = u;
		dfs(v);
	}
}
int LCA(int u,int v) {
	if (u == v) return u;
	u = pos[u], v = pos[v];
	if (u > v) swap(u, v); u ++;
	int k = Log[v - u + 1];
	return Min(g[u][k], g[v - (1 << k) + 1][k]);
}
int getdis(int u,int v) {
	return dis[u] + dis[v] - dis[LCA(u, v)] * 2;
}
bool inchain(int x,int y,int z) {
	int t = LCA(x, y), l1 = LCA(z, x), l2 = LCA(z, y);
	if (l1 == t && l2 == z) return 1;
	if (l2 == t && l1 == z) return 1;
	return 0;
}
Tree operator + (const Tree &A,const Tree &B) {
	Tree res;
	int flag = true;
	if (A.u == -1 || B.u == -1) flag = false;
	if (flag && !inchain(A.u, A.v, LCA(B.u, B.v)) && !inchain(B.u, B.v, LCA(A.u, A.v))) flag = false;
	if (!flag) {
		res.u = res.v = res.du = res.dv = -1; return res;
	}
	int z[4];
	z[0] = LCA(A.u, B.u), z[1] = LCA(A.u, B.v), z[2] = LCA(A.v, B.u), z[3] = LCA(A.v, B.v);
	sort(z, z + 4, cmp);
	res.u = z[3], res.v = z[2];
	if (res.u == res.v) {
		pa w[4];
		w[0] = mp(getdis(A.u, res.u), A.u);
		w[0] = mp(getdis(A.v, res.u), A.v);
		w[0] = mp(getdis(B.u, res.u), B.u);
		w[0] = mp(getdis(B.v, res.u), B.v);
		sort(w, w + 4);
		res.du = w[3].second, res.dv = w[2].second;
		return res;
	}
	z[0] = A.du, z[1] = A.dv, z[2] = B.du, z[3] = B.dv;
	int mx1 = -1, mx2 = -1;
	for (int i = 0; i < 4; ++i) {
		int d1 = getdis(z[i], res.u), d2 = getdis(z[i], res.v);
		if (d1 < d2 && d1 > mx1) mx1 = d1, res.du = z[i];
		else if (d2 < d1 && d2 > mx2) mx2 = d2, res.dv = z[i];
	}
	return res;
}
void build(int l,int r,int rt) {
	if (l == r) {
		scanf("%d%d", &T[rt].u, &T[rt].v); T[rt].du = T[rt].u, T[rt].dv = T[rt].v;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	T[rt] = T[rt << 1] + T[rt << 1 | 1];
}
void update(int l,int r,int rt,int p,int u,int v) {
	if (l == r) {
		T[rt].u = T[rt].du = u, T[rt].v = T[rt].dv = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if (p <= mid) update(l, mid, rt << 1, p, u, v);
	else update(mid + 1, r, rt << 1 | 1, p, u, v);
	T[rt] = T[rt << 1] + T[rt << 1 | 1];
}
Tree query(int l,int r,int rt,int L,int R) {
	if (L <= l && r <= R) {
		return T[rt];
	}
	int mid = (l + r) >> 1;
	if (R <= mid) return query(l, mid, rt << 1, L, R);
	else if (L > mid) return query(mid + 1, r, rt << 1 | 1, L, R);
	else return query(l, mid, rt << 1, L, R) + query(mid + 1, r, rt << 1 | 1, L, R);
}
int find(int x,int y,int z) {
	int lca = LCA(x, y), len = getdis(x, lca);
	if (len < z) z = getdis(x, y) - z, x = y;
	for (int i = Log[n]; ~i; --i) 
		if ((z >> i) & 1) x = f[x][i];
	return x;
}
void Ask() {
	int l, r;
	scanf("%d%d", &l, &r);
	Tree now = query(1, m, 1, l, r);
	if (now.u == -1 && now.v == -1) { puts("-1"); return ; }
	int d1 = getdis(now.du, now.u), d2 = getdis(now.dv, now.v), d = getdis(now.u, now.v);
	if (d1 >= d2 + d) {
		printf("%d\n", now.u); return ;
	}
	if (d2 >= d1 + d) {
		printf("%d\n", now.v); return ;
	}
	int mid = (d1 + d2 + d) / 2;
	if ((d1 + d2 + d) & 1) 
		printf("%d\n", min(find(now.du, now.dv, mid), find(now.du, now.dv, mid + 1)));
	else 
		printf("%d\n", find(now.du, now.dv, mid));
}
void Change() {
	int p, u, v;
	scanf("%d%d%d", &p, &u, &v);
	update(1, m, 1, p, u, v);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v); add_edge(v, u);
	}
	dfs(1);
	Log[0] = -1;
	for (int i = 1; i <= num; ++i) Log[i] = Log[i >> 1] + 1;
	for (int j = 1; j <= Log[n]; ++j) 
		for (int i = 1; i <= n; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
	for (int j = 1; j <= Log[num]; ++j) 
		for (int i = 1; i <= num; ++i) g[i][j] = Min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
	build(1, m, 1);
	int Q, opt;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &opt);
		if (opt == 1) Ask();
		else Change();
	}
	return 0;
}