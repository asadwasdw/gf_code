#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

char a[5010][5010];
char b[5010][5010];

void solve()
{

    int n;
    cin >> n;
    // assert(n % 2 == 0);
    // assert(n <= 3e3);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            // assert(a[i][j] == '.' || a[i][j] == '#');
        }
    }


    auto op = [&](int c) {
        vector<PII> v;
        for(int i = c; i <= n + 1 - c; i ++) {
            v.push_back({c, i});
            v.push_back({n - c + 1, i});
            v.push_back({i, c});
            v.push_back({i, n - c + 1});
        }

        for(int i = 0; i < v.size(); i ++) {
            int x = v[i].x, y = v[i].y;
            b[y][n + 1 - x] = a[x][y];
        }

        for(int i = 0; i < v.size(); i ++) {
            int x = v[i].x, y = v[i].y;
            a[x][y] = b[x][y];
        }
    };


    int cnt = 0;


    for(int i = 1; i <= n/2; i ++) {
        cnt = (cnt + 1) % 4;
        for(int t = 1; t <= cnt; t ++) op(i);
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << a[i][j];
        } cout << endl;
    }cout << endl;




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