#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int p1,s1,s2;
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    int l = 0, r = 0;
    for(int i = 1; i <= n; i ++) {
        if(i < m) l += (m - i) * a[i];
        if(i > m) r += (i - m) * a[i];
    }
    int ans = INF, res = 0;
    // cout << l << " " << r << endl;

    for(int i = 1; i <= n; i ++) {
        int L = l, R = r;

        if(i < m) L += (m - i) * s2;
        if(i > m) R += (i - m) * s2;
        if(ans > abs(L - R)) {
            ans = abs(L - R);
            res = i;
        }
        // cout << i << " " << L << "  " << R << " " << ans << endl;
    }

    cout << res;
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