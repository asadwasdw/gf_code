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
    vector a(n + 1, 0LL), b(n + 1, 0LL);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];

    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    ll ans = 0;

    for(int i = 1; i <= n; i ++) {
        ll x = a[i];
        int cnt = n - i + 1;

        int l = 0, r = n;

        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(b[mid] <= cnt) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        ans = max(x * l, ans);
        // cout << i << " " << l << endl;
    }
    cout << ans << endl;


    // ll l = 0, r = 1e9 + 1;

    // auto check = [&](int x) -> ll{
    //     ll res = 0;
    //     vector c(n + 1, 0);

    //     for(int i = 1; i <= n; i ++) c[i] = b[i];
        
    //     for(int i = 1, j = 1; i <= n && j <= n; i ++) {
    //         if(a[i] < x) continue;
    //         c[j] --;
    //         if(c[j] == 0) {
    //             j ++;
    //             res ++ ;
    //         }
    //     }
    //     // for(int i = 1; i <= n; i ++) cout << c[i] << " \n"[i == n];
    //     // cout << x << " " << res << endl;
    //     return res * x;
    // };
    
    // // check(2);

    // while(r - l >= 100) {
    //     int mid1 = l + (r - l) / 3;
    //     int mid2 = l + (r - l) / 3 * 2;

    //     // cout << l << " " << check(mid1) << " " << r << " " << check(mid2) << endl;
    //     if(check(mid1) >= check(mid2)) {
    //         r = mid2;
    //     } else {
    //         l = mid1;
    //     }
    // }

    // // cout << l << " " << r << endl;
    // ll ans = -1;
    // for(int i = l; i <= r; i ++) ans = max(check(i), ans);
    // cout << ans << endl;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}