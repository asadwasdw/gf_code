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
int f[N],num[N];
int find(int x) {
    if(x != f[x]) return f[x] = find(f[x]);
    return x;
}


void solve()
{
    // cin >> n;
    // for(int i = 1; i <= n; i ++) f[i] = i, num[i] = 1;
    // for(int i = 1; i <= n; i ++) {
    //     cin >> a[i];
    //     int x = i, y = a[i];
    //     x = find(x), y =find(y);
    //     if(x != y) {
    //         num[y] += num[x];
    //         f[x] = y;
    //     }
    // }

    // int ans = n;
    // for(int i = 1; i <= n;i ++) {
    //     if(f[i] == i) {
    //         ans = min(ans, num[i]);
    //     }
    // }
    // cout << ans << endl;
    cin >> n;
    int ans = 3;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[a[i]] == i && a[i] < i) ans = 2;
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