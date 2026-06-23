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
    string s, t;
    cin >> s >> t;
    string ss, tt;
    for(auto a : s) {
        if(a != 'A') ss += a;
    }

    for(auto a : t) {
        if(a != 'A') tt += a;
    }

    if(ss != tt) {
        cout << -1;
        return;
    }

    int ans = 0;
    int i = 0, j = 0;
    for(; i < s.size() && j < t.size(); ) {
        if(s[i] == t[j]) {
            i ++, j ++;
        } else if(s[i] == 'A') {
            ans ++;
            i ++;
        } else {
            ans ++;
            j ++;
        }
    }
    // cout << i << " " << j << endl;
    ans += s.size() - i + t.size() - j;
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
    return 0;
}