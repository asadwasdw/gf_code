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

int n;

void solve()
{
    cin >> n;
    ll sum = 0;
    for(int i=1; i<=n; ++i){
        ll x;cin >> x;
        sum += x;
    }
    // cout << sum << endl;
    ll res2 = (sum + n - 1) / n;
    ll res = 0;
    for(int i=62; i>=0; --i){
        if(sum > (__int128)(1ll << i) * n - n){
            res += 1ll<<i;
            for(int j = 1; j<=n; ++j)if(sum >= (1ll<<i))sum -= (1ll<<i);
        }
    }

    cout << res <<endl;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}