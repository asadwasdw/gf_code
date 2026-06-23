#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n, w, ans = 1e9;
int a[15];
bool vis[15];
int b[15];
void dfs(int id, int cnt) {
    if (cnt >= ans)return;
    if (id == 14) ans = min(ans, cnt);
    if (!a[id]) {
        dfs(id + 1, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++) {
        if (b[i] + a[id] <= w) {
            b[i] += a[id];
            dfs(id + 1, cnt);
            b[i] -= a[id];
        }
    }
    b[cnt + 1] += a[id];
    dfs(id + 1, cnt + 1);
    b[cnt + 1] -= a[id];


}

void solve()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        a[x]++;
    }

    dfs(1, 0);

    cout << ans << '\n';



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}