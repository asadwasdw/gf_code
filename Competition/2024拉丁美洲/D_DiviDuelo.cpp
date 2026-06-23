#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

void solve()
{

    ll x;cin >> x;
    
    ll sq = sqrtl(x);
    if (sq * sq == x) {
        cout << "N\n";
        return;
    }

    vector<array<ll, 2>> p;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ll cnt = 0;
            while (x % i == 0) x /= i, cnt++;
            p.push_back({i, cnt});
        }
    }
    if (x > 1) p.push_back({x, 1});
    if (p.size() > 2 || p.size() == 2 && (p[0][1] > 1 || p[1][1] > 1)) cout << "N\n";
    else cout << "Y\n";
    return;



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