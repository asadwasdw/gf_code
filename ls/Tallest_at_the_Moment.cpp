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

struct gq {
    int h, l;
} g[N];

struct que {
   int t, id;
}q[N];

int lh[N];
int ans[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> g[i].h >> g[i].l;
    }

    sort(g + 1, g + n + 1, [&](gq a, gq b){
        return a.l < b.l;
    });

    int m;
    cin >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> q[i].t;
        q[i].id = i;
    }

    for(int i = n; i >= 1; i --) {
        lh[i] = max(g[i].h, lh[i + 1]);
        // cout << i << " " << lh[i] << endl;
    }


    sort(q + 1, q + m + 1, [&](que a, que b){
        return a.t < b.t;
    });

    for(int i = 1, j = 1; i <= m; i ++) {
        while(j <= n && g[j].l <= q[i].t) j ++;
        // cout << q[i].id << " " << j << " " << lh[j] << endl;
        ans[q[i].id] = lh[j];
    }

    for(int i = 1; i <= m; i ++) {
        cout << ans[i] << endl;
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