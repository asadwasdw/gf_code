#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);  

ull a[N];
int p[N], q[N];

void solve()
{
    ll n, m, c, k;
    cin >> n >> m >> c >> k;

    ull flag = 0, g = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        flag |= a[i];
    } 
    for(int i = 1; i <= m; i ++) {
        cin >> p[i] >> q[i]; 
        if((1ull << p[i] & flag) == 0) {
            g |= 1ull << p[i];
        } 
    }

    ull ans = 1;
    for(int i = 0; i < k; i ++) {
        if((g >> i & 1) == 0) ans <<= 1;
    }
    if(ans == 0 && n == 0) cout << "18446744073709551616" << endl;
    else cout << ans - n << endl;
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