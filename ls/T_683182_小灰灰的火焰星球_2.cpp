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

long long a[N], b[N], b1[N], b2[N]; 

void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    a[n + 1] = -1;

    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    for(int i = n; i >= 1; i --) {
        b1[i] = b1[i + 1];
        b2[i] = b2[i + 1];
        if(b[i] >= b1[i]) {
            b2[i] = b1[i];
            b1[i] = b[i];
        } else if(b[i] >= b2[i]) {
            b2[i] = b[i];
        }
    }

    while(m -- ) {
        int x; cin >> x;
        int l = 1, r = n + 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(x > a[mid]) r = mid;
            else l = mid + 1;
        }
        ans += b1[l] + b2[l];
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
    return 0;
}