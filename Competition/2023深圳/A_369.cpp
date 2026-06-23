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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = -1000; i <= 1000; i ++) {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(i);
        sort(v.begin(), v.end());
        if(v[0] + v[2] == 2 * v[1]) ans++;
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