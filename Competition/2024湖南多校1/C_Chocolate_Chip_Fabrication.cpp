#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0};
//vector<vector<int>>edg(N);
int n,m;
string s[N];
queue<pair<int, int>> q[2];;
bool st[N][N];
int t;
int res = 0;
void bfs(){
    for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j){
        if(s[i][j] == 'X'){
            bool f = false;
            for(int k=0; k<4; ++k){
                int x = i + nx[k], y = j + ny[k];
                if(x < 1 || x > n || y < 1 || y > m)f = true;
                else if(s[x][y] != 'X')f = true;
            }
            if(f)q[t].push({i, j}), st[i][j] = true;
        }
    }
    while(q[t].size()){
        ++res;
        while(q[t].size()){
            auto [x, y] = q[t].front();q[t].pop();
            for(int i=0; i<4; ++i){
                int xx = x + nx[i], yy = y + ny[i];
                if(xx < 1 || xx > n || yy < 1 || yy > m)continue;
                if(st[xx][yy])continue;
                st[xx][yy] = true;
                if(s[xx][yy] == 'X')q[t^1].push({xx, yy});
                else q[t].push({xx, yy});
            }
        }
        t ^= 1;
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> s[i], s[i] = " " + s[i];
    bfs();
    bool f = false;
    for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)if(s[i][j] == 'X')f = true;
    if(!f){
        cout << 0;
        return;
    }
    cout << res << '\n';


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