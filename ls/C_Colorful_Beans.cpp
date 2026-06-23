#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
unordered_map<int,int>st;

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
       
        int x; cin >> x;
        int c; cin >> c;
        if(st[c] == 0) {
            st[c] = x;
        }
        else {
            st[c] = min(st[c], x);
        }
    }
    int ans = 0;
    for(auto t:st){
        ans = max(ans, t.second);
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