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
typedef long double db;


db dp1[N];
db n, k;
int num[N];
bool check() {
    for(int i = 1; i <= k; i ++) {
        if(!num[(int)i]) return false;
    }
    return true;
}



void solve()
{
    cin >> n >> k;

    db t = 2;

    db dp = 0;
    for(int i = 1; i <= k; i ++) {
        // dp1[i]= dp1[i - 1] + (2.0*i-1)/(i - 1) ;
        dp += k/i;
    }

    db dp2 = 1;
    for(int i = 2; i <= n; i ++) {
        dp2 += (k - dp2)/k;
    }
    cout << dp << " " << dp2 << endl;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie();
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}