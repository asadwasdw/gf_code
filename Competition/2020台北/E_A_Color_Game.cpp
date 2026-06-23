#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int dp[510][510][8];
int a[N];
void solve()
{
    map<char,int>st;
    st['R'] = 0;
    st['G'] = 1;
    st['B'] = 2;
    st['C'] = 3;
    st['M'] = 4;
    st['Y'] = 5;
    st['K'] = 6;
    string s; int n, K;
    cin >> s >> K; n = s.size();
    s = " " + s;
    // cout << s << "  " << K << endl;

    if(K == 1) {
        cout << "Yes\n";
        return;
    }
    memset(dp, -0x3f, sizeof dp);
    for(int i = 1; i <= n; i ++) {
        a[i] = st[s[i]];
        dp[i][i][a[i]] = 1;
    }

    for(int len = 2; len <= n; len ++) {
        for(int l = 1, r = len + l - 1; r <= n; l ++, r ++) {
            bool ky = false;
            for(int k = l; k < r; k ++) {
                for(int c = 0; c < 7; c ++) {
                    dp[l][r][c] = max(dp[l][r][c], dp[l][k][c] + dp[k + 1][r][c]);
                    if(dp[l][r][c] >= K) ky = true;
                }

                if(ky)for(int c = 0; c < 7; c ++) dp[l][r][c] = max(dp[l][r][c], 0ll);
            
            }
        }
    }

    
    for(int i = 0; i < 7; i ++) {
        if(dp[1][n][i] >= K) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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