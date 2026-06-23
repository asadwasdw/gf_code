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
int n,m;
char a[N][N];


void solve()
{
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    string s; cin >> s;
    for(auto t:s) {
        int tx = x, ty = y;
        if(t == 'U') tx--;
        if(t == 'D') tx++;
        if(t == 'L') ty--;
        if(t == 'R') ty++;
        if(a[tx][ty] == '.') {
            x = tx, y = ty;
        }
        // cout << t << " " << x << " " << y << endl;
    }

    cout << x << " " << y << endl;








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