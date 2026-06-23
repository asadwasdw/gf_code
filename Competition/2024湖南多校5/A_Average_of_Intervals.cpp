#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N = 1e6+10;
const int mod = (ll)1e18 + 9;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
map<int,bool>st;

void solve()
{
    int n;
    cin >> n;
    vector<int>a (n + 10);
    int s = 0, mx = -1e13, mi = 0;
    for(int i=1;i <=n; ++i){
        cin >> a[i];
        s += a[i];
        mx = max(mx, s - mi);
        mi = min(mi, s);
    }
    
    // cout << mod << " ";
    int ans = 0;
    int sum = 0;
    for(int r = 1; r <= n; r ++) {
        st[0] = true;
        sum += a[r];
        if(st[sum - mx] == true) {
            sum = 0;
            ans ++;
            st.clear();
        }
        else {
            st[sum] = true;
        }
    }
    st.clear();

    // cout << (mx % mod + mod) % mod << " ";
    // cout << ans << endl;

    // cin >> n;
    // int s = 0, mx = -1e13, mi = 0;
    // for(int i=1;i <=n; ++i){
    //     cin >> a[i];
    //     s += a[i];
    //     mx = max(mx, s - mi);
    //     mi = min(mi, s);
    // }
    // int cnt = 0;
    // int s = 0, mi = 0;
    // for(int i=1; i<=n; ++i){
    //     s += a[i];
    //     if(s - mi == mx){
    //         ++cnt;
    //         s = mi = 0;
    //     }
    //     else
    //     mi = min(mi, s);
    // }
    cout << (mx % mod + mod) % mod << ' ' << ans << endl;

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