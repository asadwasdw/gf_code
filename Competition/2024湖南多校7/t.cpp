#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m;
int a[N][N];

int cnt = 0;

void dfs(int now, int x, int y, int num) {
    cnt ++;
    if(now == n) 
    {
        a[x][y] += num;
        return;
    }
    // a[x][y] += num;
    // a[x][y] += num;
    for(int i = -1; i <= 1; i ++) {
        for(int j = -1; j <= 1; j ++) {      
            dfs(now + 1, x + i, y + j, num);
        }
    }
    dfs(now + 1, x, y, num);
}

void solve()
{
    cin >> m >> n;
    dfs(0,5,5,m);
    for(int i = 1; i <= 9; i ++) {
        for(int j = 1; j <= 9; j ++ ) {
            cout << a[i][j] << " \n"[j == 9];
        }
    }
    // cout << cnt << endl;
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