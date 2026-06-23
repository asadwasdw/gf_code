#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<=n; ++i)cin >> b[i];
    int l = 0, r = 1e9+10;
    
    auto check = [&](int mid){
        ll l = -3e18, r = 3e18;
        for(int i=1; i<=n; ++i){
            ll x = (ll)mid * b[i];
            ll _l = a[i] - x, _r = a[i] + x;
            if(_l > r || _r < l){
                return false;
            }
            l = max(l, _l);
            r = min(r, _r);
        }
        return true;
    };
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    cout << l << endl;





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