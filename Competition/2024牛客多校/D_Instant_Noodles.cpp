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
typedef unsigned long long ull;
//vector<vector<int>>edg(N);

ull h[N], p[N];
const int P = 13331;

void init() {
    p[0] = 1;
    for(int i = 1; i < N; i ++) {
        p[i] = p[i - 1] * P;
    }
}


void solve()
{
    int n, m; cin >> n >> m;
    map<int,ull> mp;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[i] = 0;
    }

    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        mp[v] = mp[v] + p[u];
    }

    map<ull,int> st;
    for(int i = 1; i <= n; i ++) {
        if(mp[i] == 0) continue;
        // cout << i << " " << mp[i] << endl;
        st[mp[i]] += a[i];
    }

    int ans = 0;
    for(auto it = st.begin(); it != st.end(); it ++) {
    
        // cout << it->second << " " << (*it).second << endl;
        ans = __gcd(ans, (*it).second);
    }
    cout << ans << endl;

}


signed main()
{
    init();
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