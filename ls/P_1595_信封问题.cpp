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

long long f[N];

void solve()
{
    int n;
    cin >> n;
    f[2] = 1;

    for(int i = 3; i <= n; i ++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }

    cout << f[n] << endl;
}

long long fac[N];

void solve2() {
    int n;
    cin >> n;
    fac[0] = 1;
    for(int i = 1; i <= n; i ++) {
        fac[i] = fac[i - 1] * i;
    }
    ll ans = 0;
    for(int i = 0;  i <= n; i ++) {
        ans += (i % 2 == 0 ? 1 : - 1) * fac[n] / fac[i];
    }
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
        solve2();
    }
    return 0;
}