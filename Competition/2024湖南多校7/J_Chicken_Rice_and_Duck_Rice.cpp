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


void solve()
{

    int c, d, r, x, y;
    cin >> c >> d >> r >> x >> y;
    int res = 0;
    if (x >= y) {
        res += min(c, r) * x;
        r -= min(c, r);
        res += min(d, r) * y;
    }  else {
        res += min(d, r) * y;        
        r -= min(d, r);
        res += min(c, r) * x;
    }
    cout << res << '\n';

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