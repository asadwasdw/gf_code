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
    int l = -1, r = -1;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x; char t; cin >> x >> t;
        if(t == 'L') {
            if(l == -1) l = x;
            ans += abs(l - x);
            l = x;
        }
        else {
            if(r == -1) r = x;
            ans += abs(r - x);
            r = x;
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