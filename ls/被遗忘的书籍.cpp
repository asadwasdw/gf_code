#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

ll t[N];

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1) res = res*a%mod; 
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
ll dp[N][3];
// 1 t
// 2 tx
// 0 
void init() {
    dp[1][1] = 1;
    dp[1][0] = 25;
    for(int i=2; i<N; i++) {
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) %mod;
        dp[i][2] = dp[i-1][1]%mod;
        dp[i][0] = (dp[i-1][1]*24%mod + dp[i-1][2]*25%mod + dp[i-1][0]*25%mod) %mod;
    }
}

void solve()
{
    ll n;cin>>n;
    cout<<((qmi(26,n)-dp[n][1]-dp[n][2]-dp[n][0])%mod+mod) %mod <<endl;;
}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}