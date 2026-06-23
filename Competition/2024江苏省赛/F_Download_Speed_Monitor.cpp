#include<bits/stdc++.h>
// #define int long long
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
typedef double db;


void print(db x) {
    if(x >= 1024) {
        cout << x/1024.0 << " MiBps\n";
    }
    else cout << x << " KiBps\n";
}


void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i], a[i] += a[i - 1];
    for(int i = k; i <= n; i ++) {
        print((db)1.0 * (a[i] - a[i - k])/k);
    }

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(8) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}