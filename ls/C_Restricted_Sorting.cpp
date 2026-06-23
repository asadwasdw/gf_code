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

int f[N];

int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x]; 
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    f[y] = x;
}


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    int mx = 0, mn = INF;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(a[i], mx);
        mn = min(a[i], mn);
        b[i] = a[i];
    }

    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    
    sort(b.begin() + 1, b.end());
    
    // for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];

    int ans = INF;

    for(int i = 1; i <= n; i ++) {
        if(a[i] != b[i]) {
            ans = min(ans, max(a[i] - mn, mx - a[i]));
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;

    // auto check = [&](int mid) -> bool {
    //     for(int i = 0; i <= n + 1; i ++) f[i] = i;

    //     for(int i = 1; i <= n; i ++) {
    //         if(abs(a[i] - mn) >= mid) merge(0, i); 
    //         if(abs(a[i] - mx) >= mid) merge(i, n + 1); 
    //     }
        
    //     for(int i = 1; i <= n; i ++) {
    //         if(a[i] != b[i]) {
    //             if(find(i) != find(0) && find(i) != find(n + 1)) return false;
    //         }
    //     }

    //     return true;
    // };

    // int l = 0, r = INF;
    // while(l < r) {
    //     int mid = (l + r + 1) >> 1;
    //     // cout << l << " " << r << " " << mid << endl;
    //     if(check(mid)) {
    //         l = mid;
    //     } else {
    //         r = mid - 1;
    //     }
    // }
    // if(l == INF) l = -1;
    // cout << l << endl;







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