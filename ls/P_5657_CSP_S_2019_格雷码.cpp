#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

string dfs(int n, ll k) {
    ll num = 1ll << (n - 1);
    if(n == 1) {
        if(k == 0) return "0";
        else return "1";
    }
    if(k < num) {
        return "0" + dfs(n - 1, k);
    } else {
        return "1" + dfs(n - 1, 2 * num - 1 - k);
    }
}


void solve()
{
    ll n, k;
    cin >> n >> k;
    cout << dfs(n , k) << endl;

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