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

int a[110][110];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) cin >> a[i][j];
    }
    int last = 1;
    for(int i = 1 ; i <= n; i ++) {
        if(last > i) last = a[last][i];
        else last = a[i][last];
    }
    cout << last;







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