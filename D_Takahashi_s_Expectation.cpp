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

int p[N], a[N], b[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i] >> a[i] >> b[i];
    }


    auto check = [&](ll mid) -> bool {

        for(int i = 1; i <= n; i ++) {
            if(mid >= p[i]) mid -= b[i];
            else return false;

            if(mid < 0) return false;
        }

        return true;

    };

    ll l = 0, r = 1e9 + 1;
    while(l < r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    for(int i = 1; i <= n; i ++) {
        if(r >= p[i]) r -= b[i];
    }

    // cout << l << " " << r << endl;

    unordered_map<int,int> st;
    int q; cin >> q;
    while(q --) {
        int x; cin >> x;
        if(x >= l) {
            x += r - l;
            cout << x << endl;
        } else if(st.count(x)) {
            cout << st[x] << endl;
        } else {
            int y = x;
            for(int i = 1; i <= n; i ++) {
                if(p[i] >= x) x += a[i];
                else x -= b[i];
                x = max(0, x);
            } 

            // st[y] = x;

            cout << x << endl;
        }
    }


    







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