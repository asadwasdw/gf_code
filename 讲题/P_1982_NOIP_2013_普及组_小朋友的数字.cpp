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
int b[N];
int c[N];

void solve()
{
    int n,p;
    cin >> n >> p;
    
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int t = 0;
    int mx = -INF;
    for(int i = 1; i <= n; i ++) {
        if(t < 0) t = 0;
        t += a[i];
        mx = max(t, mx);
        b[i] = mx;
    }

    c[1] = b[1];
    mx = b[1] + c[1];
    int ans = c[1];
    for(int i = 2; i <= n; i ++ ) {
        c[i] = mx;
        mx = max(c[i] + b[i], mx);
        ans = max(c[i], ans);
    }


    // for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++) cout << c[i] << " \n"[i == n];
    // cout << ans << endl;
    cout << ans % p << endl;





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