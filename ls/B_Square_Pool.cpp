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
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if(dx == 1 && dy == 1 && x == y) ans ++;
        if(dx ==-1 && dy == 1 && x + y == s) ans ++;
        if(dx == 1 && dy ==-1 && x + y == s) ans ++;
        if(dx ==-1 && dy ==-1 && x == y) ans ++;
    }
    cout << ans << endl;







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