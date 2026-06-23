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

ll a[N], b[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i ++) {
        cin >> a[i];

        if(i > 1) {
            int l = a[i - 1], r = a[i];
            if(r < l)swap(l, r);
            b[l] ++;
            b[r] --;
            // cout << l << " " << r << endl;
        }
    }

    for(int i = 1; i <= n; i ++) {
        b[i] = b[i - 1] + b[i];
        // cout << b[i] << " \n"[i == n];
    }

    ll ans = 0;
    for(int i = 1; i < n; i ++) {
        int A, B, C;
        cin >> A >> B >> C;
        ll res = min(A * b[i], B * b[i] + C);
        ans += res;
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