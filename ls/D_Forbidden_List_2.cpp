#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

typedef long long ll;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int>PII;
int a[N];
PII query[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> s;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        s.push_back(x);
    }

    sort(s.begin(), s.end());

    for(int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
        ll l = 0, r = INFll;

        while(l < r) {
            ll mid = l + r >> 1;
            ll cnt = upper_bound(s.begin(), s.end(), mid) - lower_bound(s.begin(), s.end(), x);

            // cout << l << " " << r << " " << mid << " " << (mid - x + 1) - cnt << endl;
            if((mid - x + 1) - cnt >= y) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;
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
    return 0;
}