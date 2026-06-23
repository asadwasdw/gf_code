#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int l[N], r[N];
int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    stack<int> sl, sr;
    a[0] = -INF, a[n + 1] = -INF;
    sl.push(0), sr.push(n + 1);
    for(int i = 1; i <= n; i ++) {
        while(a[sl.top()] >= a[i]) sl.pop();
        l[i] = sl.top() + 1;
        sl.push(i);
    }

    for(int i = n; i >= 1; i --) {
        while(a[sr.top()] >= a[i]) sr.pop();
        r[i] = sr.top() - 1;
        sr.push(i);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        // ll L = i - l[i] + 1, R = r[i] - i + 1;
        // ll len = L * (L + 1) * R * (R + 1) / 4; 
        ll len = r[i] - l[i] + 1;
        ans = max(ans, len * a[i]);
        // cout << i << " " << l[i] << " " << r[i] << " " << len << endl;
    }


    cout << ans;




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