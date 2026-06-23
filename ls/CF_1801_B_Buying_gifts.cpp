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
    vector<PII> v;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), [&](PII a, PII b) {
        return a.first < b.first;
    });

    int ans = INF;
    multiset<int> sl, sr;
    for(int i = 0; i < n; i ++) {
        sr.insert(v[i].y);
    }

    for(int i = 0; i < n; i ++) {
        sr.erase(sr.find(v[i].y));

        if(sr.size() && *prev(sr.end()) >= v[i].x) {
            ans = min(*prev(sr.end()) - v[i].x, ans);
        } else {
            if(sr.size())ans = min(v[i].x - *prev(sr.end()), ans);
            
            auto it = sl.lower_bound(v[i].x);
            if(it != sl.end()) {
                ans = min(ans, abs(*it - v[i].x));
            }
            if(it != sl.begin()) {
                ans = min(ans, abs(*prev(it) - v[i].x));
            }
        }
        
        sl.insert(v[i].y);
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
    return 0;
}