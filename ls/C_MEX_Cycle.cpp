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


void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1, 0);

    if(n % 2 == 0) {
        for(int i = 1; i <= n; i ++) a[i] = i % 2;
        if(a[x] == a[y]) a[x] = 2;
    } else {
        a[x] = 2;
        int t = 0;
        for(int i = 1; i <= n; i ++) {
            if(a[i]) continue;
            a[i] = t;
            t ^= 1;
        }
    }
    for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
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