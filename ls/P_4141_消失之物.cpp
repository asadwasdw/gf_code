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
int n, m;
cin >> n >> m;
vector dp(m + 2, 0ll);
vector cnt(n + 1, vector (m + 2, 0));
dp[0] = 1;
for(int i = 1; i <= n; i ++) {
cnt[i][0] = 1;
}

vector w(n + 1, 0);

for(int i = 1; i <= n; i ++) {
cin >> w[i];
}

for(int i = 1; i <= n; i ++) {
for(int j = m; j >= w[i]; j --) {
dp[j] += dp[j - w[i]];
dp[j] %= 10;
}
}

for(int i = 1; i <= n; i ++) {
for(int j = 1; j <= m; j ++) {
if(j >= w[i]) {
cnt[i][j] = dp[j] - cnt[i][j - w[i]] + 10; 
} else {
cnt[i][j] = dp[j];
}
cnt[i][j] %= 10;
}
}

for(int i = 1; i <= n; i ++) {
for(int j = 1; j <= m; j ++) {
cout << cnt[i][j];
}
cout << endl;
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