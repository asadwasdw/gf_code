#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10,M = 1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int w[N],c[N],s[N],st[N];

int dp[M][M];
void solve()
{
    int n , d;
    cin >> n >> d;
    for(int i=1;i<=n;i++) {
        cin>>w[i]>>c[i];
        s[i] = w[i] + s[i-1];
    }
    int m = 0;
    for(int i=1;i<=d;i++){
        int x;cin>>x;
        st[x] = 1;
        m = max(x,m);
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for(int i=1;i<=m;i++) {
        if(dp[i-1][0] < INF/2) dp[i][0] = s[i];
        for(int j=1;j<=i;j++) {
            int t1 = INF,t2 = INF;
            if(dp[i-1][j] < INF/2)t1 = max(0ll, dp[i-1][j]+w[i]);
            if(dp[i-1][j-1] < INF/2) t2 = max(0ll, dp[i-1][j-1]+w[i]-c[i]);
            dp[i][j] = min(t1,t2);
        }
        if(st[i]) {
            for(int j = 0;j <= i;j++) {
                if(dp[i][j]!=0) {
                    dp[i][j] = INF;
                }
            }
        }
    }
    int ans = -1;
    for(int j=0;j<=m;j++) {
        if(dp[m][j] < INF/2) {
            ans = j;
            break;
        }
    }
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