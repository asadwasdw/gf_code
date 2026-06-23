#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef tuple<int,int,int>PIII;
const int N=1e6+10;
const int M=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second
//vector<vector<int>>adj(N);

int id[M][M];
char a[M][M];
int dis[M][M][2];
int len;
string s;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int ne[4][N];

int get(int t, int k) {
    t %= len;
    // for(int i = t; i < min(t + 5000, len + t); i ++) {
    //     if(k == 0 && s[i] == 'D') return i - t + 1;
    //     if(k == 1 && s[i] == 'U') return i - t + 1;
    //     if(k == 2 && s[i] == 'R') return i - t + 1;
    //     if(k == 3 && s[i] == 'L') return i - t + 1;
    // }

    if(ne[k][t] < INF) {
        return ne[k][t] - t + 1; 
    }
    return -1;
}

void init() {
    memset(ne, 0x3f, sizeof ne);

    int nD = INF, nU = INF, nR = INF,nL = INF;
    for(int i = 2 * len - 1; ~i; i --) {
        if(s[i] == 'D') nD = i;
        if(s[i] == 'U') nU = i;
        if(s[i] == 'R') nR = i;
        if(s[i] == 'L') nL = i;
        ne[0][i] = nD, ne[1][i] = nU, ne[2][i] = nR, ne[3][i] = nL;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cin >> s;
    len = s.size();
    s += s;

    init();

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    memset(dis, 0x3f, sizeof dis);

    priority_queue<array<int,4> ,vector<array<int,4>>, greater<array<int,4>>> q;
    q.push({0, 0, 1, 1});
    dis[1][1][0] = dis[1][1][1] = 0;
    
    while(q.size()) {
        auto[d0, d1, x, y] = q.top(); q.pop();

        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(a[tx][ty] == '#') continue;
            int w = get(d1, k);
            if(w == -1) {
                if(dis[tx][ty][0] > d0 + 1) {
                    dis[tx][ty][0]  = d0 + 1;
                    dis[tx][ty][1] = d1 + 1;
                    q.push({dis[tx][ty][0], dis[tx][ty][1], tx, ty});
                }
            } else {
                if(dis[tx][ty][0] > d0 || (dis[tx][ty][0] == d0  && dis[tx][ty][1] > d1 + w)) {
                    dis[tx][ty][0]  = d0;
                    dis[tx][ty][1] = d1 + w;
                    q.push({dis[tx][ty][0], dis[tx][ty][1], tx, ty});
                }
            }
        }
    }

    cout << dis[n][m][0] << " " << dis[n][m][1] << endl; 
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