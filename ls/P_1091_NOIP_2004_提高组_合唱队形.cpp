#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n;
int a[N];
int dp1[N],dp2[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(a[i] > a[j])dp1[i] = max(dp1[i],dp1[j] + 1);
        }
    }

    for(int i = n; i >= 1; i --) {
        for(int j = n + 1; j > i; j --) {
            if(a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << n - ans;


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