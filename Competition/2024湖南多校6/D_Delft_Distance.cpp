#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1500;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
const long double PI = acos(-1);
//vector<vector<int>>edg(N);
int n,m;
// int a[N];
int a[N][N];
long double dp[N][N];

void solve()
{
    // memset(dp,0x3f,sizeof dp);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            char x;
            cin >> x;
            if(x == 'O') {
                // cout << 2 * i << " " << 2 * j << endl;
                a[2 * i][2 * j] = 1;
            }
        }
    }
    n = n * 2 + 1, m = m * 2 + 1;

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            dp[i][j] = (n+m)*5;
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++) cout << a[i][j] << " \n"[j == m]; 
    // }
    // cout << 2.5*PI<< endl;

    dp[1][1] = 0;
    // cout << "00.00 ";
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(i == 1 && j == 1) continue;
            if(i % 2 == 0 && j % 2 == 0) continue;
            dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + 5;
            if(a[i - 1][j] || a[i][j - 1]) 
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 2.5 * PI);
            }

            // cout << dp[i][j] << " \n"[j == m];
        }
    }

    cout << dp[n][m] << endl;


    







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(10) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}