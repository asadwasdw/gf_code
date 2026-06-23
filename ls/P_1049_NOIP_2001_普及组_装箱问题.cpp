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

int dp[35][N]; // 凑出体积恰好为j时的
int p[35][N];

void solve()
{
    int V, n;
    cin >> V >> n;

    dp[0][0] = 1;

    for(int i = 1; i <= n; i ++) {
        int v;
        cin >> v;
        for(int j = 1; j <= V; j ++) {
            if(dp[i - 1][j]) {
                dp[i][j] = 1;
                p[i][j] = j; // 存储上一个状态的体积
            }

            if(j >= v && dp[i - 1][j - v]) {
                dp[i][j] = 1;
                p[i][j] = j - v; // 存储上一个状态的体积
            }
        }
    }

    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= V; j ++) {
            cout << dp[i][j] << " \n"[j == V];
        }
    }

    if(dp[n][V] == 0) {
        for(int i = n; i >= 1; i --) {
            int v = V - p[i][V];
            if(v)cout << V << " " << p[i][V] << " " << v << endl;
            V -= v;
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