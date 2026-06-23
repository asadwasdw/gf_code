#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int l[N], r[N];
ll a[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i ++) {
        cin >> l[i] >> r[i];
        a[l[i]] ++, a[r[i] + 1] --;
    } 

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
        if(a[i] == 0) ans ++;
    }

    for(int i = 1; i <= n; i ++) {
        if(a[i] == 1) a[i] = 1;
        else a[i] = 0;
        // cout << i << " " << a[i] << endl;
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= m; i ++) {
        cout << ans + (a[r[i]] - a[l[i] - 1]) << endl;
    } 

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