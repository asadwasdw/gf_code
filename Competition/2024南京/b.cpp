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


void solve()
{
    int cnt[2][3];
    memset(cnt, 0, sizeof cnt);
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i ++) {
        cnt[i%2][s[i] - '0'] ++;
    }
    int ans = abs(cnt[0][0] - cnt[1][0]) + abs(cnt[0][1] - cnt[1][1]);
    int c = cnt[0][2] + cnt[1][2];
    if(c <= ans) {
        ans -= c;
    } else {
        ans = c - ans&1;
    } 
    cout << ans << endl;

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