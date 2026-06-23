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

ll c[N], s[N];
int n, w;

ll get(int l) {
    ll res = 0;
    int r = l + w - 1;
    if(r <= 2 * w) {
        res = s[r] - s[l - 1];
    } else {
        // cout << l << " " << r << " " << (s[l] - s[r - 2 * w - 1]) << endl;
        // res = s[2 * w] - (s[l - 1] - s[r - 2 * w]);
        res = (s[2 * w] - s[l - 1]) + s[r - 2 * w];
    }
    return res;
}

void solve()
{
    cin >> n >> w;
    for(int i = 0; i <= max(n, 2 * w); i ++) c[i] = s[i] = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    for(int i = 2 * w + 1; i <= n; i ++) {
        int j = i % (2 * w);
        if(j == 0) j = 2 * w;
        c[j] += c[i];
    }

    for(int i = 1; i <= 2 * w ; i ++) {
        s[i] = s[i - 1] + c[i];
    }
    ll ans = INFll;

    for(int i = 1; i <= 2 * w; i ++) {
        ll res = get(i);
        ans = min(res, ans);
        // cout << i << " " << ans << endl;
    }
    cout << ans << endl;
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