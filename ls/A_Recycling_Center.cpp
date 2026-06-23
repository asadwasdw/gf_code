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
    ll n, c;
    cin >> n >> c;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, [&](int a, int b){
        return a > b;
    });
    int ans = n;
    for(int i = 1; i <= n; i ++) {
        if(a[i] <= c) {
            ans --;
            c /= 2;8 
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