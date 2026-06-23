#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N][N];
int dis[N][N];
int st[N][N];


int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct T {
    int d,x,y,step;
    inline bool operator > (const T &x) const {//小根堆，重载大于号，小的在前面
        return d>x.d;
    }
};

void solve()
{
    int k;
    cin >> n >> m >> k;    
    int sx, sy;
    cin >> sx >> sy;

    for(int i = 1; i <= n; i ++)    
        for(int j = 1; j <= m; j ++) 
            cin >> a[i][j];
    
    int ans = 0;

    for(int Tx = 1; Tx <= n; Tx ++) 
        for(int Ty = 1; Ty <= m; Ty ++) {
            // if(a[sx][sy] > a[Tx][Ty]) continue;

            priority_queue<T,vector<T>, greater<T>> q;
            q.push({0, sx, sy, 0});
            memset(dis, 0x3f, sizeof dis);
            memset(st, 0, sizeof st);
            dis[sx][sy] = 0;

            while(q.size()) {
                auto [d,x,y,step] = q.top();q.pop();
                // cout << x << " " << y << endl;
                if(st[x][y]) continue;
                if(step == k) continue; 
                st[x][y] = true;
                
                for(int k = 0; k < 4; k ++) {
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    // cout << tx << " " << ty << endl;
                    if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
                    if(st[tx][ty]) continue;
                    if(a[tx][ty] > a[Tx][Ty]) continue;

                    int w = a[Tx][Ty] - a[tx][ty];
                    if(dis[tx][ty] > dis[x][y] + w) {
                        dis[tx][ty] = dis[x][y] + w;
                        q.push({dis[tx][ty],tx,ty,step + 1});
                    }
                }
            }

            // cout << a[Tx][Ty] * k << " " << dis[Tx][Ty] << " " << Tx << " " << Ty << endl;
            ans = max(ans,a[Tx][Ty] * k - dis[Tx][Ty]);
        }
    

    cout << ans;

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