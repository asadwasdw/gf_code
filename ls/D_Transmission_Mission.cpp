#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a;
    for(int i = 1; i <= n; i ++) {
        ll x; cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    // for(auto t : a) cout << t << endl;
    ll ans = a[a.size() - 1] - a[0];

    vector<ll> b;
    for(int i = 0; i < a.size() - 1; i ++) {
        ll t = a[i + 1] - a[i];
        b.push_back(t);
    }

    sort(b.begin(), b.end());
    m --;
    for(int i = b.size() - 1; i >= 0; i --) {
        if(m > 0) {
            m --;
            ans -= b[i];
        }
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
        solve();
    }
}