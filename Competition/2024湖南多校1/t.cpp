#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int dp[N][2];

void solve()
{
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    //dp[0][1] 不合法，不可能进行(0,1)操作
    //dp[i][0] 保证前i个满足要求，且此时没有进行(i,i+1)操作
    //dp[i][1] 保证前i个满足要求， 且进行了(i,i+1)操作

    for(int i = 1; i <= n/2; i ++) {
        if(s[i] == s[n-i+1]) {
            dp[i][0] = min (
                dp[i-1][0], // 无需进行操作
                dp[i-1][1] + 1 // 进行(i-1,i)
            );

            dp[i][1] = min (
                dp[i-1][0] + 1,// 补上一次(i-1,i),使i复原
                dp[i-1][1]     // 前面的影响过s(i)了,刚好这次换回来
            ) + 1; //进行了(i,i+1)
        }
        else {
            dp[i][0] = min (
                dp[i-1][0] + 2, // 操作2次， 可以保证s(i),s(i-1)都满足调条件
                dp[i-1][1]  // 前面操作影响到了s(i),使s(i)可行
            );

            dp[i][1] = min (
                dp[i-1][0] ,// 
                dp[i-1][1]     //不管前面发生了什么,这一次进行(i,i+1)都可以使s(i)可行
            ) + 1; //进行了(i,i+1)
        }
    }
    cout<<min(dp[n/2][1], dp[n/2][0])<<endl;



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