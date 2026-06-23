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
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N];
ll n, k;

bool check(ll mid) {
    ll cnt = 0;
    for(int i = 1; i <= n; i ++) {
        ll d = max(mid - a[i], 0ll);
        cnt += (d + i - 1) / i;
        if(cnt > k) return false;
    }
    // cout << mid << " " << cnt << endl;
    return cnt <= k;
}

void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    ll l = 0, r = 4e18;

    while(l < r) {
        ll mid = l + r + 1>> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;

    }
    cout << l;
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