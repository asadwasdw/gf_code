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

int a[N];
int dp[N];

void solve()
{
    int n;
    cin >> n;
    int gcd = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        gcd = __gcd(a[i], gcd);
    }
    if(gcd != 1) {
        cout << "INF";
        return;
    }

    dp[0] = 1;

    for(int i = 1; i <= n; i ++) {
        for(int j = a[i]; j < N; j ++) {
            dp[j] |= dp[j - a[i]];
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i ++) {
        if(dp[i] == 0) {
            cout << i << endl;
            cnt ++;
        }
    }
    cout << cnt;

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