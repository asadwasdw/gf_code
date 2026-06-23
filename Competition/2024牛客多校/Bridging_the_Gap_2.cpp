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
    int n, l, r;
    cin >> n >> l >> r;
    if(l <= n && n <= r) {
        cout << "Yes\n";
        return;
    }

    int cnt = (n - r + (r - l - 1)) / (r - l);
    // cout << cnt << endl;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] % 2 == 0 && a[i] > 1)  a[i] -- ;
    }


    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        sum += a[i] / 2;
    }
    if(sum >= l * cnt) cout << "Yes";
    else cout << "No";

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