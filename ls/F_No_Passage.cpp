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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void solve()
{
    int h, w, k;
    cin >> h >> w >> k;

    vector dis(h + 1, vector(w + 1, -1));
    vector cnt(h + 1, vector(w + 1, 0));

    queue<PII> q;

    for(int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = 0;
        cnt[x][y] = 4;
        q.push({x, y});
    }

    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        
        for(int i = 0; i < 4; i ++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 1 || tx > h || ty < 1 || ty > w) continue;
            cnt[tx][ty] ++;
            if(cnt[tx][ty] == 2) {
                dis[tx][ty] = dis[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }

    ll ans = 0;

    for(int i = 1; i <= h; i ++) {
        for(int j = 1; j <= w; j ++) {
            // cout << dis[i][j] << " \n"[j == w];
            ans += max(0, dis[i][j]);
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
}