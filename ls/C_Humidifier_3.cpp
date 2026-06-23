#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9, K = 1e5 + 9;
char a[N][N];
bool vis[N][N];
int dis[N][N];
struct node {
	int x, y, r;
} no[K];
int xx[] = {0, 1, 0, -1, 0};

int main() {
	int n, m, nn = 0,k;	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
		cin >> a[i][j];
		if(a[i][j] == 'H') {
			no[++nn] = {i, j, k};
		}
	}
	
	
	// for(int i = 1; i <= k; i ++) cin >> no[i].x >> no[i].y >> no[i].r;


	sort(no + 1, no + nn + 1, [&](node a, node b) -> bool {
		return a.r > b.r;
	});
	
	using pii = pair<int, int>;
	queue<pii> qu;
	qu.push({no[1].x, no[1].y});
	vis[no[1].x][no[1].y] = true;
	dis[no[1].x][no[1].y] = no[1].r;
	int now = 2;
	
	while(!qu.empty()) {
		pii pi = qu.front();	qu.pop();
		int x = pi.first, y = pi.second;
		// cout << x << " " << y << endl;
		while(now <= nn && no[now].r == dis[x][y]) {
			int fx = no[now].x, fy = no[now].y, fr = no[now].r;
			now ++;
			if(vis[fx][fy] == true) continue;
			qu.push({fx, fy});
			vis[fx][fy] = true;
			dis[fx][fy] = fr;
		}
		if(dis[x][y] == 0) continue;
		for(int i = 1; i <= 4; i ++) {
			int fx = x + xx[i], fy = y + xx[i - 1];
			if(fx < 1 || fx > n || fy < 1 || fy > m) continue;
			if(vis[fx][fy] == true || a[fx][fy] == '#') continue;
			qu.push({fx, fy});
			vis[fx][fy] = true, dis[fx][fy] = dis[x][y] - 1;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) ans += vis[i][j];
	cout << ans;

	return 0;
}
/*



*/