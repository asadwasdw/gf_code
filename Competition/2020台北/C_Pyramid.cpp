#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);



void solve()
{
    int n, K; cin >> n >> K;
    int x,y;
    x = y = 1;

    vector<int>dp(n + 10);
    dp[1]= K - 1;
    for(int i = 1; i < n; i ++) {
        vector<int>gf(n + 10);
        for(int j = 1; j <= i; j ++) {
            gf[j] += (dp[j]+1)/2;
            gf[j + 1] += (dp[j])/2;
        }
        // cout << x << " " << y << endl;
        if(dp[y] % 2) {
            y ++;
        }
        x ++;

        dp.swap(gf);
    }
    cout << y - 1 << endl;
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