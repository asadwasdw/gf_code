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
    int n, k;cin >> n >> k;
    vector<int> a(1 << n);
    
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    auto f = [&](vector<int> a) -> vector<int>{
        vector<int> p;
        set<int> s;

        for (auto x : a) s.insert(x);
        vector<int> tmp;
        int m = (a.size());
        for (int i = 0; i < m; i++) {
            if (s.find(a[i]) == s.end()) continue;
            auto it = s.upper_bound(a[i] + k);
            it--;
            if (*it == a[i]) {
                if (tmp.size() == 0) {
                    tmp.push_back(a[i]);
                }else {
                    p.push_back(*it);
                    p.push_back(tmp.back());
                    tmp.pop_back();
                }
                s.erase(it);
            }else {
                p.push_back(a[i]);
                p.push_back(*it);
                s.erase(it);
                s.erase(a[i]);
            }
        }
        return p;
    };

    
    // for (int i = 0; i < (1 << n); i++) {
    //     cout << p[i] << ' ';
    // }

    ll ans = 0;
    ll cnt  = 5;
    while(n!=0) {
        vector<int>p = f(a);
        vector<int>p2;
        for(int i = 0; i < (1<<n) ; i+=2) {
            p2.push_back(max(p[i],p[i+1]));
            if(abs(p[i]-p[i+1])<=k)ans++;
        }
        n--;
        // for(auto t:p)cout << t<<' ';cout << '\n';
        a = p2;
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