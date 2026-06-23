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

int n, m; 
int a[N];
PII query[N];
int ans =0;
void dfs(int u) {
    if(u == n + 1) {
        bool ky = true;
        for(int i = 1; i <= m; i ++) {
            if(a[query[i].second] - a[query[i].first - 1] < 2) ky = false;
        }

        if(ky) {
            int res = 1;
            for(int i = 1; i <= n; i ++) {
                if(a[i] - a[i - 1] == 0) res *= 6;
                else res *= 2;
            }
            ans += res;
        }
        return;
    }

    for(int i = 0; i <= 2; i ++) {
        a[u] = a[u - 1] + i;
        dfs(u + 1);
    }

}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> query[i].first >> query[i].second;
    }
    dfs(1);
    cout << ans << endl;

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