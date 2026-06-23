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


void solve()
{
    ll n, d;
    cin >> n >> d;
    __int128 ans = 0;
    for(int i = 1; i <= 9; i ++) {
        ans = ans * 10 + i;
    }
    ans = ans * 10 + d;

    ll x = n;
    while(x) {
        ans = ans * 10;
        x /= 10;
    }

    ll t = ans / n;
    if(ans % n) t ++;
    assert(t <= 2e10);
    cout << t << endl;
    // cout << (ll)(t * n) << endl;
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