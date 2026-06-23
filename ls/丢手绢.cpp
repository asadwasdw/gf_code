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

int a[N];




int b[N][25];
int n;

void init() {
    for(int i = 1; i <= 2 * n; i ++) b[i][0] = a[i];

    for(int i = 1; i <= 20; i ++) {
        for(int j = 1; j <= 2 * n; j ++) {
            b[j][i] = max(b[j][i - 1], b[min(2ll * n, j + (1ll << (i - 1)))][i - 1]);
        }
    }
}

ll get(int l, int r) {
    if(r < l) return 0;
    int lg = log2(r - l + 1);
    // cout << l << " " << r << " " << lg << " " << b[l][lg] << " " << b[r - (1ll << lg) + 1][lg] << endl;
 
    return max(b[l][lg], b[r - (1ll << lg) + 1][lg]);
}



void solve()
{
   
    cin >> n;

    ll mx = 0, mxid = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];

        if(a[i] > mx) {
            mx = a[i];
            mxid = i;
        }
    }

    init();

    ll ans = 0;

    for(int i = 1; i < n; i ++) {
        int mid = mxid + i;
        ll m = a[mid];
        ll l = get(mxid + 1, mid - 1);
        ll r = get(mid + 1, mxid + n - 1);
        // cout << m << " " << mx << " " << " " << l << " " << r << endl; 

        if(l * r * m * mx)ans = max((mx + m) * (l + r), ans);
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