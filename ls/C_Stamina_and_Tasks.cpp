#include<bits/stdc++.h>
#define double long double
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
    vector<double> a(n + 1);
    vector<double> p(n + 1);
    vector<double> s(n + 1);
    double S = 1;
    double sum = 0;
    double ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> p[i];
        // if(fabs(p[i] - 100) <= 0.1) p[i] = 99.99999;
        p[i] = (100 - p[i]) / 100;
        ans += a[i] * S;
        s[i] = S;
        S *= p[i];
        // cout << ans << " " << p[i] << " " << s[i] << endl;
    }
    // cout << ans << endl;
    for(int i = n; i >= 1; i --) {
        double res1 = a[i];
        double res2 = sum * (1 - p[i]);

        // cout << i << " " << res1 << " " << res2 << " " << sum << endl;

        if(res2 > res1) {
            ans = ans - s[i] * res1 + s[i] * res2; 
        } else {
            sum = sum * p[i] + a[i];
        }
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