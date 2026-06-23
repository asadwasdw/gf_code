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
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
    }
    vector<int> a;
    int anst = 0;
    for(int i = 1; i <= n; i ++) {
        bool ky = false;
        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            if(v[i] % v[j] == 0) ky = true;
        }
        if(!ky)a.push_back(v[i]);
        else anst ++;
    }

    n = a.size();
    int ans = INF;
    sort(a.begin(), a.end());
    int T = 0;
    for(int i = 1;  i < n; i ++) T = __gcd(T, a[i]);
    if(a[0] <= T) ans = n;
    // cout << 
    
    int cz = 1;
    for(int i = 0; i < n; i ++) {
        int res = 0;
        for(int j = 0; j < n; j ++) {
            if(i == j) continue;
            res ++;
            if(a[j] % a[i]) res ++;
            if(a[j] % a[i] == 1) cz = 0;
        }
        ans = min(ans, res);
    }
    ans = min(n + cz, ans);

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i == j) continue;
            int t = a[j] % a[i];
            int gcd = 0;
            for(int k = 0; k < n; k ++) {
                if(k == i) continue;
                gcd = __gcd(gcd,a[k]);
            }
            if(gcd%t == 0) {
                ans = min(ans, n);
                // cout << i << " " << j << " " << t << " " << gcd << endl;
            }
        }
    }
    // cout << ans << " " << anst << endl;


    cout << ans + anst << endl;
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