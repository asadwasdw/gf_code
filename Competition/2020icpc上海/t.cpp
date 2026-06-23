#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dp[N][N];
PII pre[N][N];

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                pre[i][j] = {i-1,j-1};
            }

            if(dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                pre[i][j] = {i - 1,j};
            }

            if(dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                pre[i][j] = {i,j - 1};
            }
        }
    }

    cout << dp[n][m] << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    stack<char>s;
    while(n > 0 && m > 0) {
        if(a[n]==b[m])s.push(a[n]);

        PII t = {pre[n][m].first,pre[n][m].second};
        n = t.first;
        m = t.second;
    }

    while(s.size()) {
        cout << s.top();
        s.pop();
    }cout << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}