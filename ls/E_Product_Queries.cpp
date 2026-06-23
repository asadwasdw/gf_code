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
    int n;
    cin >> n;
    vector a(n + 1, 0ll), cnt(n + 1, 0ll), ans(n + 1, INFll);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        // cnt[a[i]] ++;
        ans[a[i]] = 1;
    }

    // for(int i = 1; i <= n; i ++) {
    //     if(ans[i] >= INF / 2) cout << "-1 ";
    //     else cout << ans[i] << " ";  
    // }cout << endl;

    for(ll i = 2; i <= n; i ++) {
        if(ans[i] == INFll) continue;
        ll x = i * i;
        while(x <= n) {
            ans[x] = min(ans[x / i] + ans[i], ans[x]);
            x *= i;
        }
    }


    // for(int i = 1; i <= n; i ++) {
    //     if(ans[i] >= INF / 2) cout << "-1 ";
    //     else cout << ans[i] << " ";  
    // }cout << endl;

    for(int i = 2; i <= n; i ++) {
        int t = sqrt(i);
        for(ll x = 2; x <= t; x ++) {
            if(i % x == 0) {
                ll y = i / x;
                ans[i] = min(ans[i], ans[x] + ans[y]);
            }
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     if(ans[i] >= INFll/2) continue;
    //     for(int j = i; j <= n; j += i) {
    //         ans[j] = min(ans[j], ans[i] + ans[j / i]); 
    //     }
    // }

    for(int i = 1; i <= n; i ++) {
        if(ans[i] >= INFll / 2) cout << "-1 ";
        else cout << ans[i] << " ";  
    }cout << endl;
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
    return 0;
}