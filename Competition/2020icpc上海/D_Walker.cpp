#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-10;
//vector<vector<int>>edg(N);

int sign(db x) {
    if (fabs(x) <= eps) return 0;
    return x > 0 ? 1 : -1;
}

void solve()
{

    db n, p1, v1, p2, v2;
    cin >> n >> p1 >> v1 >> p2 >> v2;

    if (p1 > p2) {
        p1 = n - p1;
        p2 = n - p2; 
    }
    //  cout << p1 << ' ' << v1 << ' ' << p2 << ' ' <<v2 << '\n';
    if (v1 > v2) {
        p1 = n - p1;
        p2 = n - p2; 
        swap(v1, v2);
        swap(p1, p2);
    }
    // cout << p1 << ' ' << v1 << ' ' << p2 << ' ' <<v2 << '\n';


    auto check = [&](db t) -> bool{
        if (sign(t * v1 - n - min(p1, (n - p1)) >= 0)) return true;
        if (sign(t * v2 - n - min(p2, (n - p2)) >= 0)) return true;

        // if (sign(t * v1 - p1) < 0 || sign(t * v2 - (n - p2)) < 0) return false;

        bool ok = false;

        {
            db limit = min(p2, max(t * v1 - p1, p1));
            ok |= sign(t * v1 - p1) >= 0 && sign(t * v2 - (n - limit) - min(p2 - limit, n - p2)) >= 0;
        }
        {
            db limit = max(p1, min(p2, n + n - p2 - t * v2));
            ok |= sign(t * v2 - (n - p2)) >= 0 && sign(t * v1 - limit - min(limit - p1, p1)) >= 0;
        }
        {
            {
                bool ok2 = true;
                ok2 &= sign(t * v1 - p1) >= 0 && sign(t * v2 - (n - p2)) >= 0;
                ok2 &= sign(t * v1 + t * v2 - n - (p2 - p1)) >= 0;

                ok |= ok2;
            }
            {
                bool ok2 = true;
                ok2 &= sign(t * v1 - (n - p1)) >= 0 && sign(t * v2 - p2) >= 0;
                ok |= ok2;
            }
        }
        
        
        return ok;
        
        
    };

    db l = 0, r = 1e9;
    while (r - l > eps) {
        db m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
        
    }
    
    cout << l << '\n';

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    cout << setprecision(15) << fixed;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}