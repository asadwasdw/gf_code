#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    s = s + s;
    int n = t.size();
    bool ky = false;
    for(int i = 0; i < n; i ++) {
        if(t == s.substr(i,n))ky = true;
        // cout << t << ' ' << s.substr(i,n) << '\n';
    }

    if(ky) cout << '1';
    else cout << '0';








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