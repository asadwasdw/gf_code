#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        // a[i] = i;
    }
    sort(a + 1, a + n + 1);
    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];

    auto calc = [&](int x) -> int {
        if(x < 0) return INF;
        int cnt = 0;
        int l = -INF;
        for(int i = 1; i <= n; i ++) {
            if(l + x < a[i]) {
                cnt ++;
                l = a[i];
            }
        }
        return x + cnt;
    };

    // cout << calc(0) <<

    // for(int i = 0; i <= n; i++) {
    //     cout << i << " " << calc(i) << endl;
    // }

    int l = 0;int r = 2e5+1 ;
    while(r - l > 2) {
        int mid1 = l + (r - l)/3;
        int mid2 = r - (r - l)/3;

        if(calc(mid1) > calc(mid2)) {
            l = mid1;
        } else r = mid2;
    }

    int ans = INF;
    for(int i = l; i <= r; i ++) ans = min(ans, calc(i));
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
        solve();
    }
}