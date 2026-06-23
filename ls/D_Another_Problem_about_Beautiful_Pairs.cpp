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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int nn = sqrt(n) + 1;
    ll ans = 0;
    for(int k = 1; k <= nn; k ++) {
        // unordered_map<ll,int> cnt;
        vector<int>cnt(n + 1, 0);
        for(int j = 1; j <= n; j ++) {
            if(a[j] == k) {
                ans += cnt[j];
            }

            if(a[j] <= nn && 1ll * a[j] * k + j <= n) {
                cnt[1ll * a[j] * k + j] ++;
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(a[i] > nn) {
            for(int j = i - a[i]; j >= 1; j -= a[i]) {
                if(1ll * a[i] * a[j] == i - j) {
                    ans ++;
                }
            }

            for(int j = i + a[i]; j <= n; j += a[i]) {
                if(1ll * a[i] * a[j] == j - i) {
                    ans ++;
                }
            }
        }
    }
    

    cout << ans << endl;
  


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