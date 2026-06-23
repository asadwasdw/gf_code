#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector L(n + 10, vector (20, n + 1));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int l = 1, r = 1, sum = 0; l <= n; l ++) {
        while(r <= n && sum + a[r] <= k) sum += a[r ++]; 
        // cout << l << " " << r << endl; // [l,r)
        L[l][0] = r;
        sum -= a[l]; 
    }
    for(int i = n; i; i --) {
        for(int j = 1; j < 20; j ++) {
            L[i][j] = L[L[i][j - 1]][j - 1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x = i;
        for(int j = 20; ~j; j --) {
            if((m >> j) & 1) x = L[x][j];
        }
        // cout << i << " " << x << endl;
        ans = max(x - i, ans);
    }
    cout << ans << endl;








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}