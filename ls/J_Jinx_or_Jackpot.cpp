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

double ans = 0;

void solve()
{

    int n, k;
    cin >> n >> k;


    for(int i = 1; i <= n; i ++) {
        int p; cin >> p;
        long double P = p / 100.0;

        ans += (1000.0 / n) * powl(P, k) * (1ll << (k));
    }


    // for(int i = 1; i <= n; i ++) {
    //     int p; cin >> p;
    //     double P = p / 100.0;
    //     double res = (P * pow(P, k - 1) * (1ll << (k - 1)) * 1000 + (1 - P) * 1000);
    //     ans += 1.0 / n * res;
    // }

    cout << ans << endl;

    cout << max(0.0,  (ans - 1000)) << endl;







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