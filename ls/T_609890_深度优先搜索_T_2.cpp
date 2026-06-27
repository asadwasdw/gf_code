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

ll f[N];
int m = 3;
int ans = 0;

void dfs(ll n, int id) {
    // cout << n << " " << id << endl;
    if(n == 1) {
        ans ++;
        return;
    }

    if(id > 61 || f[id] > n) {
        return ;
    }

    if(n % f[id] == 0) {
        // cout << n << " " << f[id] << " " << ans << endl;
        dfs(n / f[id], id);
    }

    dfs(n, id + 1);
}

void solve()
{
    ll n;
    cin >> n;


    dfs(n,3);
    cout << ans << endl;
    ans = 0;






}


signed main()
{
    f[1] = f[2] = 1;
    for(int i = 3; i <= 100; i ++) {
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] > 1e18) break;
    }
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}