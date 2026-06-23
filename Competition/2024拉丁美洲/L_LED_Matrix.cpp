#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N],b[N];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool ky = true;
    for(int i = 1; i <= n ;i ++) {
        for(int j = 1; j <= m; j ++) {
            char t; cin >> t;
            if(t == '-') a[i] = true;
         
        }
  

        for(int j = 1; j <= k; j ++) {
            char t; cin >> t;
            if(t == '*') b[i] = true;
        }

        if(b[i] & a[i]) ky = false;
    }
    if(ky) cout << "Y";
    else cout << "N";







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