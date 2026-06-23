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
    vector a(n, 0ll);
    
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    ll g = a[0];
    for(int i = 1; i < n; i ++) {
        g = __gcd(a[i], g);
    }

    for(int i = 0; i < n; i ++) {
        a[i] /= g;
        cout << a[i] << " \n"[i == n - 1];
    }
    ll ans = 1;
    for(int i = 1; i < n; i ++) {
        if(a[i - 1] > a[i]) {
            a[i - 1] /= ans;
            if(a[i - 1] > a[i]) {
                ans = ans * (a[i - 1]/ a[i]);
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
}