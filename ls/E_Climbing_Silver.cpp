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

void solve()
{    
    int n, c;
    cin >> n >> c;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    vector<int> last(n + 1, n);
    for(int j = 1; j <= n; j ++) {
        for(int i = n; i >= 1; i --) {
            last[j] --;
            if(s[i][j] == '#') break;
        }
    }

    vector<int> dp(n + 1, 0);
    vector<int> ok(n + 1, 0);

    dp[c] = 1;
    for(int i = n; i >= 1; i --) {
        vector<int> dp2 = ok;
        for(int j = 1; j <= n; j ++) {
            if(dp[j] == 0) continue;
            for(int k = -1; k <= 1; k ++) {
                int y = j + k;
                if(y < 1 || y > n) continue;
                if(s[i - 1][y] == '.' || i - 1 == last[y]) {
                    dp2[y] = 1;
                }

                if(i - 1 == last[y]) {
                    ok[y] = 1;
                }
            }
        }
        swap(dp2, dp);
    }
    for(int i = 1; i <= n; i ++) {
        cout << dp[i] << " \n"[i == n];
    }

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
    return 0;
}