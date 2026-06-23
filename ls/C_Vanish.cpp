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


void solve()
{
    int n, k;
    cin >> n >> k;
    map<int,int> cnt;
    ll sum = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        cnt[x] += 1;
        sum += x;
    }
    vector<ll> v;
    for(auto [x, y] : cnt) {
        v.push_back(1ll * x * y);
    }
    sort(v.begin(), v.end(),[&](ll a, ll b){
        return a > b;
    });
   
    for(int i = 0; i < min((int)v.size(), k); i ++) {
        sum -= v[i];
    }
    cout << sum;
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