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

ll a[N];
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1,[&](ll a, ll b){
        return a > b;
    });

    ll sum = 0;

    for(int i = 1; i <= n; i ++ ) {
        if(i + k > n) {
            sum += a[i];
        }

        if(sum >= x) {
            cout << i;
            return;
        }
    }
    cout << "-1";
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
    return 0;
}