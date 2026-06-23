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

int n, a[N];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; ++i)cin >> a[i];
    ll res = 0;
    for(int i=2; i<n; ++i){
        ll l = 0, r=  0;
        // int mi = a[i];
        for(int j=1; j<i; ++j){
            // mi = min(mi, a[j]);
            l = max(l, (ll)min(a[j], a[i]) * (i - j ));
        }
        // mi = a[i];
        for(int j=i+1; j<=n; ++j){
            // mi = min(mi, a[j]);
            r = max(r, (ll)(min(a[j], a[i]) * (j - i )));
        }
        res = max(res, l + r);
    }
    cout << res << endl;






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