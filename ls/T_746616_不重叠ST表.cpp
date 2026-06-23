#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1000000007;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

ll b[N][20];
ll a[N];
ll lg2[N];
void solve()
{
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i][0] = a[i];
    }

    for(int j = 1; j < 20; j ++ ) {
        for(int i = 1; i <= n; i ++) {
            if(i + (1 << (j - 1)) <= n)b[i][j] = b[i][j - 1] * b[i + (1 << (j - 1))][j - 1] % mod;
        }
    }

    ll ans = 0;

    while(q --) {
        int l, r;
        cin >> l >> r;

        ll res = 1;
        for(int i = 20; i >= 0; i --) {
            if(l + (1 << i) - 1 <= r) {
                res = res * b[l][i] % mod;
                l += (1 << i);
            }
        }
        ans ^= res;
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