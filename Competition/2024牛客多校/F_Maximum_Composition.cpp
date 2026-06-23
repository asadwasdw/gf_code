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

map<int,int> mp;

void solve()
{
    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        int x = rand() % 2;
        if(x) {
            res ++;
        }
        else {
            mp[res]++;
            res = 0;
        }
    }

    int ans = -1;
    res = 0;
    for(auto [u, v] : mp) {
        if(v >= res) ans = u;
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