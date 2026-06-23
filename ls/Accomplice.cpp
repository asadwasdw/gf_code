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

ll a[N];

void solve()
{
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        if(r - l < d) continue;
        a[l] ++, a[r - d + 1] --;
    }
    ll ans = 0;
    for(int i = 1; i <= 1e6; i ++) {
        a[i] += a[i - 1];
        ans += a[i] * (a[i] - 1) / 2;
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