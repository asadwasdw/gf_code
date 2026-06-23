#include<bits/stdc++.h>
#define int long long
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
    int n; cin >> n;
    vector a(n + 1, 0);
    vector l(n + 10, 0);
    vector r(n + 10, 0);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    string s; cin >> s; s = " " + s;

    for(int i = 1; i <= n; i ++) {
        l[i] = l[i - 1];
        if(s[i] == 'L') l[i]++;
    }

    for(int i = n; i; i --) {
        r[i] = r[i + 1];
        if(s[i] == 'R') r[i]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) ans += a[i] * min(l[i], r[i]),assert(ans >= 0);
    cout << ans << endl;
    assert(ans >= 0);
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