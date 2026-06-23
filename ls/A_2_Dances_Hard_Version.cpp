#include<bits/stdc++.h>
// #define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m;
int a[N];
int b[N];
int c[N];
ll ans = 0;

bool check(int mid) {
    for(int i = 2; i <= n; i++)c[i] = a[i];
    c[1] = mid;
    sort(c + 1, c + n + 1);

    int res = 0;

    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= n && c[i] >= b[j]) {
            j++;
        }

        res = max(res, j - i);
    }
    // for(int i = 1; i <= n; i++) cout << c[i] <<" ";cout << endl;
    // for(int i = 1; i <= n; i++) cout << b[i] <<" ";cout << endl;
    // cout<<mid<<" "<<res<<endl;
    return res > ans;
}


void solve()
{
    ans = 0;
    cin>>n>>m;
    a[1] = 1;
    for(int i = 2; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
 

    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= n && a[i] >= b[j]) {
            j++;
        }
        ans = max(ans, (ll)j - i);
    }
   
    int l = 1, r = m + 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    //  cout<<ans<<endl;
    //  cout<<l<<endl;

    ll sum = 1ll*ans*(l-1) + (ans + 1) * (m - l + 1);
    cout << sum <<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}