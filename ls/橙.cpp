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

set<int> s;

void dfs(int len, ll x, int sum) {
    if(len > 9 || x > 1e6) {
        return; 
    } 

    if(sum % 13 == 0) {
        s.insert(x);
    }

    for(int i = 0; i <= 9; i ++) {
        dfs(len + 1, x * 10 + i, sum + i);
    }
}

void init() {
    dfs(0,0,0);
}

void solve(){

    int l, r; 
    cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; i ++) {
        int res = 0;
        int x = i;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        if(res % 13 == 0) {
            ans ++;
            if(ans == 2) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    






}


signed main()
{
    // init();
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