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


int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    bool ky = true;
    if(n > 2) ky = false;
    if(a[2] - a[1] < 2) ky = false;
    if(ky) cout << "YES\n";
    else cout << "NO\n";


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