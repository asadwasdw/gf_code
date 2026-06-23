#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e8;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
int s[N];


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i];
    }

    int ans = 0;
    int r = 0;

    // cout << r << endl;
    for(int i = n; i > 1; i --) {
        while(r < n && a[r + 1] + a[i] < mod) {
            r ++;
        }
 
        ans += (i - 1) * a[i] + s[i - 1];
        ans -= max(0ll,(i - 1 - r)) * mod;
        // cout << i << " " << r << endl;
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