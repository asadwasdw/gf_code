#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

bitset<2010> c[1000];
bitset<2010> st[2010];

int a[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int j = 1; j <= m; j ++) {
        for(int i = 0; i < 1000; i ++) c[i].reset();
        for(int i = 1; i <= n; i++) {
            c[a[i][j]][i] = 1; 
        }

        for(int i = 1; i <= n; i ++) {
            st[i] ^= c[a[i][j]];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        st[i][i] = 0;
        ans += st[i].count();
    }
    cout << ans/2 <<endl;
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