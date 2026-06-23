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


int dp[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        for(int j = m; j >= x; j --) {
            dp[j] |= dp[j - x];
        }
    }

    for(int j = m; j >= 0; j --) {
        if(dp[j]) {
            cout << j;
            break;
        }
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