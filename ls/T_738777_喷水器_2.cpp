#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve()
{
    int n, m, D;
    cin >> n >> m >> D;
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
    //  queue<array<int,3>> q;
    vector dis(n + 1, vector(m + 1, 0));
    vector a(n + 1, vector(m + 1, '.'));

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }   
    } 

    while(D --) {
        int x, y, z;
        cin >> x >> y >> z;
        q.push({z + 1, x, y});
    }

    while(q.size()) {
        auto [d, x, y] = q.top(); q.pop();
        // cerr << d <<  " " << x << " " << y << endl;
        if(d <= dis[x][y]) continue;
        dis[x][y] = d;
        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;  
            if(a[tx][ty] == '#') continue;
            if(d - 1 < dis[tx][ty]) continue;
            // cerr << d - 1 <<  "-" << tx << "-" << ty << endl;

            q.push({d - 1, tx, ty});
        }
    }
    int ans = 0;
	// cout << a[95][27] << endl;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(dis[i][j]) {
				ans ++;
				// cout << i << " " << j << endl;
			}
			
            // cout << dis[i][j] << " \n"[j == m];
        }
    }

    cout << ans << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}