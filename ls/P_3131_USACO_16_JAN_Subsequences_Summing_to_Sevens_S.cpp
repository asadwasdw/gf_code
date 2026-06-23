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
    vector<int> a(n + 1, 0);
    vector<int> s(n + 1, 0);
    vector<int> pre(7, n + 1);
    pre[0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = (s[i - 1] + a[i]) % 7;
        ans = max(ans, i - pre[(s[i])]);
        pre[s[i]] = min(i, pre[s[i]]);
    }
    cout << ans;







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