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



void solve2() {
    int n;
    cin >> n;
    vector<PII> v(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin() + 1, v.end(), [&](PII a, PII b) {
        return a.first < b.first;
    });
    vector<int> a(n + 1, 0), dp(n + 1, 0);
    vector<int> h(n + 1, INF);
    h[0] = -1e9;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        a[i] = v[i].second;
        int j = lower_bound(h.begin() + 1, h.end(), a[i]) - h.begin();
        h[j] = a[i];
        ans = max(j, ans);
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
        solve2();
    }
    return 0;
}