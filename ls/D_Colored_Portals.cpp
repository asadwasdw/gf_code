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

map<string,int> id;
struct Q{
    int x, y, ansid;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector ans(q + 1, -1);

    auto check = [&](string a, string b) -> bool {
        return a[0] == b[0] || a[1] == b[0] || a[0] == b[1] || a[1] == b[1];
    };

    vector<string> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    map<PII,vector<Q>> query;

    for(int i = 1; i <= q; i ++) {
        int x, y; cin >> x >> y;
        if(check(a[x], a[y])) {
            ans[i] = abs(x - y);
        }
        else {
            int idx = id[a[x]], idy = id[a[y]];
            if(idx > idy) swap(idx, idy);
            query[{idx, idy}].push_back({x, y, i});
        }
    }

    for(auto [t, q] : query) {
        vector<int> v;
        for(int i = 1; i <= n; i ++) {
            if(id[a[i]] != t.first && id[a[i]] != t.second) v.push_back(i);
        }

        sort(v.begin(), v.end());

        for(auto [x, y, ansid] : q) {
            int mid = (x + y)/2;
            int res = INF;
            int it = lower_bound(v.begin(), v.end(), mid) - v.begin();
            if(it < v.size())res = min(abs(x - v[it]) + abs(y - v[it]), res);

            if(it - 1 >= 0 && it - 1 < v.size())  res = min(abs(x - v[it - 1]) + abs(y - v[it - 1]), res);
            if(it - 2 >= 0 && it - 2 < v.size())  res = min(abs(x - v[it - 2]) + abs(y - v[it - 2]), res);
            
            if(it + 1 < v.size()) res = min(abs(x - v[it + 1]) + abs(y - v[it + 1]), res);
            if(it + 2 < v.size()) res = min(abs(x - v[it + 2]) + abs(y - v[it + 2]), res);
            
            if(res == INF) res = -1;
            ans[ansid] = res;
        }
    }

    for(int i = 1; i <= q; i ++) {
        cout << ans[i] << endl;
    }
}


signed main()
{
    id["BG"] = 1;
    id["BR"] = 2;
    id["BY"] = 3;
    id["GR"] = 4;
    id["GY"] = 5;
    id["RY"] = 6;
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