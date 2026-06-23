#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);


bool check(auto itl, auto itr, int &lt, int &rt) {
    auto[tl, xl] = *itl;
    auto[tr, xr] = *itr;

    int dx = abs(xr - xl);
    if(xr != 1) {
        // cout << xl << " " << xr << endl;
        // cout << tr << "-" << dx << endl;
        rt = min(rt, tr - dx); // 当前时间 - 至少的花费时间
    }

    if(xl == 1 && (tl + xl)%2 != (tr + xr)%2 && (tr - tl) >= dx) {
        lt = max(lt, tl + 1);
        return lt <= rt;
    }

    return (tl + xl)%2 == (tr + xr)%2 && lt <= rt && (tr - tl) >= dx;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    map<int,int> mp;
    int lt = 0, rt = INF;
    mp.emplace(0,1);
    bool bad = false;

    while(m --) {
        int op; cin >> op;
        if(op == 0) {
            int t, x; cin >> x >> t;
            if(mp.contains(t)) {
                if(x != mp[t]) {
                    bad = true;
                }
                continue;
            }

            auto [it, ii] = mp.emplace(t, x); 
            // assert(ii == true);
            auto itl = prev(it);
            auto itr = next(it);

            if(!check(itl, it, lt, rt)) {
                bad = true;
            }

            if(itr != mp.end() && !check(it, itr, lt, rt)) {
                bad = true; 
            }
        } else if(op == 1) {
            if(bad) cout << "bad\n";
            else cout << lt << "\n";
        } else {
            if(bad) cout << "bad\n";
            else if(rt >= INF) cout << "inf\n";
            else cout << rt << "\n";
        }
    }

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