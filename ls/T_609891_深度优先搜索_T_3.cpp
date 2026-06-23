#include<bits/stdc++.h>
using namespace std;
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


vector<int> ans;

bool check(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i ++) {
        if(x % i == 0) return false;
    }

    return true;
}
int n;

void dfs(int id, int res) {
    // cerr << id << " "<< res << endl;
    if(res && !check(res)) return;
    if(id > n) {
        cout << res << endl;
        return;
    }

    for(int i = 1; i <= 9; i ++) {
        dfs(id + 1, res * 10 + i);
    }
}


void solve()
{
    cin >> n;

    dfs(1, 0);






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