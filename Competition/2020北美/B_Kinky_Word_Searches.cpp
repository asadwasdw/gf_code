#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=15;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
char a[N][N];
string s;
int num;

int dx[]={0,-1,-1,0,1,1,1,0,-1};
int dy[]={0,0,1,1,1,0,-1,-1,-1};
map<array<int,5>,int>mp;

bool dfs(int x,int y,int k,int now, int cnt) {

    if(mp[{x,y,k,now,cnt}]) return false;
 
    if(now == num && a[x][y] == s[now] && cnt == 0) {
        return true;
    }
    if(((int)s.size() - now) < cnt - 1)  {
        return false;
    }
    if(cnt < 0) return false;
    if(a[x][y] != s[now]) return false;
    for(int K = 1; K <= 8; K ++) {
        int tx = x + dx[K];
        int ty = y + dy[K];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(a[tx][ty] != s[now + 1]) continue;
        if(dfs(tx,ty,K,now +1, cnt - (K != k))) {
            return true;
        }
    }
    mp[{x,y,k,now,cnt}] = 2;
    return false;
}


void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) cin >> a[i][j];
    }

    int cnt;
    cin >> cnt;
    cin >> s;
    num = s.size();
    s = " " + s;
   
    // cout << num << endl;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] == s[1]) {
                if(cnt == 0 && num == 1) {
                    cout << "YES";
                    return;
                }
                for(int k = 1; k <= 8; k ++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 1 || x > n || y < 1 || y > m) continue;
                    if(dfs(x,y,k,2,cnt)) {
                        // cout << x << " " << y << k << endl;
                        cout << "YES";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO";


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