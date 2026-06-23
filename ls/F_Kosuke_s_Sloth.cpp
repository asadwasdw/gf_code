#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

ll f[N];

void solve()
{
    ll n, k; cin >> n >> k;
    f[1] = f[2] = 1;
    for(ll i = 1; i < N ; i ++) {
        if(i >= 3) f[i] = (f[i - 1] + f[i - 2]) % k;
        if(f[i] % k == 0) {
            cout << i * n % mod << endl;
            break;
        }
    }

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