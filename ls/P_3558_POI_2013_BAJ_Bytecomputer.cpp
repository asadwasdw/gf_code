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

// map<int,int> dp[N];
int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = -1; j < 2; j ++) dp[i][j] = INF;
    // }
    map<int,int> dp1, dp2;
    for(int j = -1; j <= 1; j ++) dp1[j] = INF;
    dp1[a[1]] = 0;
    int ans = INF;
    for(int i = 2; i <= n; i ++) {
        for(int j = -1; j <= 1; j ++) dp2[j] = INF;
        
        for(int j = -1; j <= 1; j ++) {
            for(int cnt = 0; cnt <= 2; cnt ++) {
                int z = a[i] + cnt * j;
                if(z >= j && z <= 1 && z >= -1) {
                    dp2[z] = min(dp2[z], dp1[j] + cnt);
                }
            }
        }
        swap(dp1, dp2);
    }

    for(int i = -1; i <= 1; i ++) ans = min(ans, dp1[i]);
    if(ans >= INF) cout << "BRAK";
    else cout << ans;

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