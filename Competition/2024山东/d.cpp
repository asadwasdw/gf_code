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
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int p, a, b, q, c, d, m, t;
    cin >> p >> a >> b;
    cin >> q >> c >> d;
    cin >> m >> t;

    int now = min(m/p,max(0ll,(t - b - d) / (a + c)));

    auto calc = [&]() {
        if(now == 0) return INF;
        return a * now + b + c * now + d;    
    };

    auto jsw = [&] {
        if(now == 0) return INF;
        return now * (q - p);
    };

  
    while(t >= calc() && now > 0) {
        int cnt = min(t/calc(), (((p) - m % (p)) + jsw() - 1) / jsw());
        t -= cnt * calc();
        m += cnt * jsw();

        now = min(m/p,max(0ll,(t - b - d) / (a + c)));
        // cout << cnt << " " << now << " " << calc() << " " << jsw() << endl;
    }

    cout << m << endl;







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
}