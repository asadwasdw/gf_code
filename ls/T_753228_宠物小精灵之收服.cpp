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

void solve()
{
  //为了统一变量， 修改了题目中变量的含义，以保证和文章通顺
    int n, m, k;
    cin >> m >> k >> n;

    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; i ++) {
        int v1, v2;
        cin >> v1 >> v2;
        for(int j = m; j >= v1; j --) {
            for(int z = k - 1; z >= v2; z --) {
                dp[j][z] = max(dp[j][z], dp[j - v1][z - v2] + 1);
            }
        }
    }
  // 切记，至少给皮卡丘留一滴血，即最大的血量花费是k - 1
    int ans1 = dp[m][k - 1], ans2 = 0;
    for(int z = 0; z < k; z ++) {
        if(ans1 == dp[m][z])ans2 = max(ans2, k - z);
    }
    cout << ans1 << " " << ans2 << endl;
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