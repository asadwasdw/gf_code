#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = 1e3+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int x[M],y[M];
int dp[50][2][2][2];
int dfs(int cnt, bool isx, bool isy, bool is0) {
    if(cnt == -1) return 1;
    if(dp[cnt][isx][isy][is0]) return dp[cnt][isx][isy][is0];

    int numx = (isx?x[cnt]:1);
    int numy = (isy?y[cnt]:1);
    int ans = 0;
    for(int i = 0; i <= numx; i++) {
        for(int j = 0; j <= numy; j++) {
            if(i & j) continue;
            int t = 1;
            if(is0 && (i||j)) t = cnt + 1;
            ans += dfs(cnt - 1, isx && (i == numx), isy && (j == numy), !i && !j && is0 ) * t %mod;
            ans %= mod;
        }
    }
    return dp[cnt][isx][isy][is0] = ans;
}

void solve()
{
    memset(dp, 0, sizeof dp);
    int X,Y;
    cin >> X >> Y;
    int len = 0;
    while(X || Y) {
        x[len] = (X&1);
        y[len] = (Y&1);
        X >>= 1;
        Y >>= 1;
        len ++;
    }
    int ans = dfs(len - 1, 1, 1, 1);// 从高位到地位，x是否顶，y,当前数是否为0;
    ans = (ans - 1 + mod )%mod;
    cout << ans << '\n'; 

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