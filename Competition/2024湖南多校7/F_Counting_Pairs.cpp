#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int p[N];
vector<int> pr;
void init(int n) {
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) p[i] = i, pr.emplace_back(i);
        for (auto j : pr) {
            if (i * j > n) break;
            p[i * j] = j;
            if (p[i] == j) break;
        }
    }
}

void solve()
{

    ll a, b; cin >> a >> b;
    init(b);
    ll res = 1;
    for (auto x : pr) {
        ll cnt = a / x * x;
        while (cnt <= a) cnt += x;
        if (cnt <= b) res = res * 2 % mod;
    }
    cout << res << "\n";




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