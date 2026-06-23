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


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), dp(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        for(int j = 0; j < i; j ++) {
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

void solve2() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), dp(n + 1, 0);
    vector<int> h(n + 1, INF);
    h[0] = -1e9;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        int j = lower_bound(h.begin() + 1, h.end(), a[i]) - h.begin();
        h[j] = a[i];
        ans = max(j, ans);
    }
    cout << ans << endl;
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
        solve2();
    }
    return 0;
}