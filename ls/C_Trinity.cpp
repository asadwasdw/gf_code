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


void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    int r = 0;
    for(int l = 0; l < n - 1; l ++) {
        while(r < n && a[l] + a[l + 1] > a[r]) r ++;
        // cout << a[l] + a[l + 1] << " " << a[r] << endl;
        ans = max(r - l, ans);
        // cerr << l + 1 << " " << r + 1 << endl;
    }
    cout << n - ans << endl;
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