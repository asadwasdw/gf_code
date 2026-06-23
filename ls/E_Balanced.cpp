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


void solve()
{
    int n; cin >> n;
    vector a(n, 0ll);
    vector add(n * 2 + 5, 0ll);
    vector pre(n * 2 + 5, 0ll);
    vector ans(n * 2 + 5, 0ll);
    for(int i = 0; i < n; i ++) cin >> a[i];

    for(int i = 0; i < n/2; i ++) {
        int j = n - i - 1;
        ll diff = a[j] - a[i] - add[i];
        add[i] += 2 * diff;
        add[i + 1] += diff;

        pre[n - i] += diff; 
        pre[n + i + 2] -= diff; 
    }

    for(int i = 2; i < 2 * n; i ++) {
        pre[i] += pre[i - 2];
    }

    for(int i = 0; i < 2 * n; i ++) {
        a[i%n] += pre[i] * 2;
        a[(i - 1 + n) % n] += pre[i];
        a[(i + 1 + n) % n] += pre[i];
        ans[i%n] += pre[i];
    }


    add.assign(2 * n + 5, 0ll);
    pre.assign(2 * n + 5, 0ll);

    for(int i = n/2 - 1; i >= 0; i --) {
        ll diff = a[i] - (a[i + 1] + add[i + 1]);
        add[i] += diff;
        pre[i + 1] += diff;
        pre[n - i] -= diff;
    }

    for(int i = 2; i < 2 * n; i ++) {
        pre[i] += pre[i - 2];
    }

    for(int i = 0; i < 2 * n; i ++) {
        a[i%n] += pre[i] * 2;
        a[(i - 1 + n) % n] += pre[i];
        a[(i + 1 + n) % n] += pre[i];
        ans[i%n] += pre[i];
    }

    ll mn = ans[0];
    for(int i = 1; i < n; i ++) mn = min(ans[i],mn);
    for(int i = 0; i < n; i ++) ans[i] -= mn;

    // for(int i = 0; i < n; i ++) cout << a[i] << " "; cout << endl;
    for(int i = 0; i < n; i ++) cout << ans[i] << " "; cout << endl;
    


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