#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

#define int long long
//vector<vector<int>>adj(N);

PII op[N];
void solve()
{
    int q; cin >> q;
    string s; cin >> s;
    s = " " + s;

    for(int i = 1; i <= q; i ++) {
        cin >> op[i].first >> op[i].second;
    }

    int L, R; cin >> L >> R;

    for(int i = 1; i <= q; i ++) {
        auto [l, r] = op[i];
        // cout << l << " " << r << endl;
        string t = s.substr(l, r - l + 1);
        string t2;
        for(int j = 0; j < t.size(); j ++) if(j % 2 == 1) t2 += t[j];
        for(int j = 0; j < t.size(); j ++) if(j % 2 == 0) t2 += t[j];
        // cout << r + 1 << " " << s.size() << endl;
        s = s.substr(0, r + 1) + t2 + (r < s.size()? s.substr(r + 1) : "");
        s = s.substr(0, R + 100);
        // cout << s << endl;
    }

    for(int i = L; i <= R; i ++) cout << s[i];








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