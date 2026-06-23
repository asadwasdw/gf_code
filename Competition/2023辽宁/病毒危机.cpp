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

//vector<vector<int>>adj(N);


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1, 0);
    int k; cin >> k;
    for(int i = 0; i < k; i ++) {
        int x; cin >> x;
        a[x] = 1;
    }
    int ans = 1;
    for(int i = 2; i <= n; i ++) {
        cin >> k;
        bool cg = false;
        while(k --) {
            int x; cin >> x;
            if(a[x]) cg = true;
        }
        if(cg) ans ++;
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