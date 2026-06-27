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

struct op{
    int x, y;
    char c;
}o[N];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 10, vector<int> (m + 10, 0));
    o[0].c = 'A';
    for(int i = 1; i <= q; i ++) {
        cin >> o[i].x >> o[i].y >> o[i].c;
        a[o[i].x][o[i].y] = i;
    }

    for(int i = n; i >= 1; i --) {
        for(int j = m; j >= 1; j --) {
            a[i][j] = max({a[i + 1][j], a[i][j + 1], a[i][j]});
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            // cout << a[i][j] << " \n"[j == m];
            cout << o[a[i][j]].c;
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