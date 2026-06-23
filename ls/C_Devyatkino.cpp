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
int ans;

bool check(ll x) {
    while(x) {
        if(x%10 == 7) return true;
        x /= 10; 
    }
    return false;
}
ll t[20];
int num = 0;
void dfs(ll x, int cnt, int l, int r) {
    num ++;
    if(cnt >= ans) {
        return;
    }
    if(check(x)) {
        ans = min(ans, cnt);
        return;
    }

    for(int i = l; i <= r; i ++) {
        dfs(x + t[i], cnt + 1, i, r);
    }
}

void solve()
{
    ans = 9;
    ll n;
    cin >> n;
    for(int i = 1; i < 10; i ++) {
        dfs(n, 0, i, i);
    }

    cout << ans << endl;
}


signed main()
{
    for(int i = 1; i <= 15; i ++) t[i] = t[i - 1] * 10 + 9;
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