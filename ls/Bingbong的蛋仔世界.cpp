#include<bits/stdc++.h>
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


void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    int ans = 0;
    int t = max(n,m)/2;
    int x1 = n/2 + 1, y1 = m/2 + 1;
    while(k --) {
        int x, y;
        cin >> x >> y;
        if(abs(x - x1) + abs(y - y1) <= t) ans ++;
    }
    cout << ans << endl;








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
}