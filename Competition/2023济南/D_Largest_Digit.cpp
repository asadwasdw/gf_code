#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

int f(int x) {
    int res = 0;
    while(x) {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}


void solve()
{
    int la, lb, ra, rb;
    cin >> la >> ra >> lb >> rb;
    int ans = 0;
    for(int i = la; i <= min(la + 10, ra); i ++) {
        for(int j = lb; j <= min(lb + 10, rb);j ++) {
            ans = max(f(i + j), ans);
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