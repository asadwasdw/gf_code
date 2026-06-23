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

vector<int> a[N];
int dp[110][10010]; 
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        while(cin >> x) {
            if(x == -1) break;
            a[i].push_back(x);
        }
    }


    for(int k = 1; k <= n; k ++) {
        dp[k][0] = 1;
        for(int i = 0; i < a[k].size(); i ++) {
            int v = a[k][i];
            for(int j = 100 * 100; j >= v; j --) {
                dp[k][j] |= dp[k][j - v];
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= 100 * 100; j ++) {
        bool ky = true;
        for(int k = 1; k <= n; k ++) {
            // cout << dp[k][j] << " \n"[k == n];
            ky &= dp[k][j];
        }
        if(ky) ans = j;
    }

    cout << ans;
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