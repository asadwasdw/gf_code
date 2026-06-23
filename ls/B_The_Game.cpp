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

    int n, m;cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    multiset<int> s1, s2;
    int cnt = 0;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        s1.insert(a[i]);
        cnt += b[i] - a[i];
        if (a[i] > b[i]) ok = false;
    }
    for (int i = m; i < n; i++) s2.insert(a[i]);

    if (!ok || s2.size() < cnt) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    while (s2.size() > cnt) {
        auto it = s2.begin();
        
    }


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}