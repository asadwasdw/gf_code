#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

const int N=1e3+10;
int a[N][N];
int d[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef pair<int,int>PII;
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }

    queue<PII> q;
    for(int i = 1; i <= n; i ++) {
        q.push({0, i});
        q.push({i, 0});
        q.push({i, n + 1});
        q.push({n + 1, i});
    }

    while(q.size()) {
        PII t = q.front(); q.pop();
        int x = t.first, y = t.second;
        
        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
            if(d[tx][ty]) continue;
            if(a[tx][ty] == 1) continue;
            q.push({tx, ty});
            d[tx][ty] = 1;
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(d[i][j]) cout << "0 ";
            else if(a[i][j] == 1) cout << "1 ";
            else cout << "2 ";
        }
        cout << endl;
    }
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