#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];

void solve()
{


    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>dp(n + 10, n);
    dp[n + 1] = 0;

    for(int i = n; i >= 1; i--) {
        dp[i] = dp[i + 1] + 1;
        if(i + a[i] <= n){
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
        }
        cout << i << " " << dp[i] <<endl;
    }
    cout<<dp[1]<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}