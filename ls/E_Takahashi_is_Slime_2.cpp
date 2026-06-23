#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

void print(__int128 x)
{
    if (!x) return ;
    if (x < 0) putchar('-'),x = -x;
    print(x / 10);
    putchar(x % 10 + '0');
}

struct node
{
    int x, y;
    __int128 w;
    inline bool operator > (const node &x) const {//小根堆，重载大于号，小的在前面
        return w>x.w;
    }
};

int a[510][510];
bool st[510][510];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    int sx, sy;
    cin >> sx >> sy;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    __int128 ans = a[sx][sy];
    st[sx][sy] = true;

    priority_queue<node,vector<node>,greater<node>> q;
    for(int k = 0; k < 4; k ++) {
        int x = sx + dx[k];
        int y = sy + dy[k];
        if(x < 1 || x > n || y < 1 || y > m) continue;
        st[x][y] = true;
        node t = {x, y, a[x][y]};
        q.push(t);
    }

    while(q.size()) {
        node u = q.top(); q.pop();
        // cerr << u.w * p << " " << ans << endl;
        if(u.w * p < ans) {
            ans += u.w;
            for(int k = 0; k < 4; k ++) {
                int x = u.x + dx[k];
                int y = u.y + dy[k];
                if(x < 1 || x > n || y < 1 || y > m) continue;
                if(st[x][y]) continue;
                st[x][y] = true;
                node t = {x, y, a[x][y]};
                q.push(t);
            }

        } else {
            break;
        }
    }
    print(ans);
    







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