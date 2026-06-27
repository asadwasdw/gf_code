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

char a[110][110];

void solve()
{
    int n, m;
    cin >> n >> m;
    int l = INF, r = - INF, u = INF, d = - INF;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                l = min(j, l);
                r = max(j, r);
                u = min(i, u);
                d = max(d, i);
            }
        }
    }
    // cout << l << " " << r << 

    for(int i = u; i <= d; i ++) {
        for(int j = l; j <= r; j ++) {
            cout << a[i][j];;
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