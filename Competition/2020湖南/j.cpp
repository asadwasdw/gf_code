#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e5+10, mod = 1e9+7;

int fa[N];
int find(int k){
    return k == fa[k] ? k : fa[k] = find(fa[k]);
}
int mid;
struct node
{
    int u,v,a,b;
    bool operator < (const node &e) const{
        return (ll)b * mid + a < (ll)e.b * mid + e.a;
    }
};


void solve(){
    int n,m,l,r;
    while(cin >> n >> m >> l >> r){
        vector<node> e;
        for(int i=1; i<=m; ++i){
            int u,v,a,b;
            cin >> u >> v >> a >> b;
            e.push_back({u, v, a, b});
        }
        auto check = [&](int m){
            ll res = 0;
            mid = m;
            sort(e.begin(), e.end());
            for(int i=1; i<=n; ++i)fa[i] = i;
            for(auto &[u, v, a, b] : e){
                int f1 = find(u), f2 = find(v);
                if(f1 != f2){
                    fa[f2] = f1;
                    res += (ll)b * mid + a;
                }
            }
            return res;
        };
        ll res = 5e18;
        res = min(check(l), res);
        res = min(check(r), res);

        // while(r - l + 1 > 3){
        //     int m1 = l + (r - l + 1) / 3, m2 = r - (r - l + 1) / 3;
        //     ll val = check(m1), val2 = check(m2);
        //     if(val < val2){
        //         r = m2-1;
        //     }
        //     else if(val > val2)l = m1 +1;
        //     else l = m1, r = m2;
        // }
        
        // for(int i=l; i<=r; ++i)res = min(res, check(i));
        cout << res << endl;
    }


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}