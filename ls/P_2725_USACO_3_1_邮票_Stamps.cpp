#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

const int N=2e6+10;
int dp[N];
void solve()
{
    int n, k, m = 2e6;
    cin >> k >> n;

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for(int i = 1; i <= n; i ++) {
        int v, w = 1;
        cin >> v;
        for(int j = v; j <= m; j ++) {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }

    
    for(int j = 0; j <= m; j ++) {
        if(dp[j + 1] > k) {
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