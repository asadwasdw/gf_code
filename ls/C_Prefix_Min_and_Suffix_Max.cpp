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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> ans(n + 1, 0);
    int t = INF;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        t = min(a[i], t);
        if(a[i] <= t) ans[i] = 1;
    }

    t = - INF;
    for(int i = n; i >= 1; i --) {
        t = max(a[i], t);
        if(a[i] >= t) ans[i] = 1;
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i];
    } 
    cout << endl;

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