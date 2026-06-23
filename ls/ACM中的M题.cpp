#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


map<int,int> num;
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
    }

    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        num[x] ++;
    }
    int ans = 0;
    for(auto [a, b] : num) {
        if(b == 1) {
            cout << "-1";
            return;
        }
        ans += (b + 1)/2;
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