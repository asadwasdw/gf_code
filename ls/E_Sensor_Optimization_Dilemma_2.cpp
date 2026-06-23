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

//vector<vector<int>>adj(N);

ll a[N],b[N],p[N],q[N];
int n, X;

bool check(int mid) {
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        double pa = 1.0*p[i]/a[i], qb = 1.0 * q[i]/b[i];
        ll res = INFll;
        if(pa > qb) {
            swap(p[i], q[i]);
            swap(a[i], b[i]);
        }
        
        int num = (mid + a[i] - 1) / a[i];
        res = num * p[i];
        for(int j = num - 1; j >= max(0ll,num - 2000); j --) {
            int num2 = (mid - j * a[i] + b[i] - 1) / b[i];
            res = min(res, p[i] * j + q[i] * num2);
            // cout << j << " " << num2 << " " << p[i] * j + q[i] * num2 << endl;
        }
        // cout << res << endl;
        ans += res;
        if(ans > X) return false;
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << a[i] << " " << p[i] <<" "<<b[i] << " " << q[i] << endl;
    // }
    return true;
}

void solve()
{
   
    cin >> n >> X;
    ll l = 0, r = 1e9 + 10;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // cout << check(3) << endl;
    // cout << check(4) << endl;
    // cout << check(5) << endl;

    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;


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