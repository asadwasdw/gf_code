#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int j = 1; j <= n; j ++) {
        int t;cin >> t;
        edg[a[j]].push_back(t);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        sort(edg[i].begin(),edg[i].end());
        for(int j = 0; j < (int)(edg[i].size() - 1); j ++) ans += edg[i][j];
    }
    cout << ans;







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