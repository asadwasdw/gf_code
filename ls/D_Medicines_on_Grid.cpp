#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n, m;
char c[N][N];
int a[N][N];
int st[N][N];

int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};
void solve()
{
    int Sx,Sy,Tx,Ty;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m;j ++) {
            cin >> c[i][j];
            if(c[i][j] == 'S') {
                Sx = i, Sy = j;
            }
            if(c[i][j] == 'T') {
                Tx = i;
                Ty = j;
            }
        }
    }

  

    int qe;
    cin >> qe;
    while(qe--){
        int x,y,z;
        cin >> x >> y >>z;
        a[x][y] = z;
    }


    priority_queue<array<int,3>> q;
    q.push({a[Sx][Sy],Sx,Sy});
    memset(st, -1, sizeof st);
    int cnt = 50;

    while(q.size() ) {
        auto [z,x,y] = q.top();q.pop();
        // cout << x << " " << y  << " "<< z << endl;

        if(st[x][y] >= z) continue;
        //
        st[x][y] = z;
        
        if(z <= 0)continue;
        a[x][y] = 0;
        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(c[tx][ty] == '#') continue;
        
            if(st[tx][ty] > z + a[tx][ty] - 1) continue;
            q.push({z + a[tx][ty] - 1, tx, ty});
           
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j++) cout << st[i][j] << " \n"[j == m];
    // }

    if(st[Tx][Ty] != -1) cout << "Yes\n";
    else cout << "No\n";






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