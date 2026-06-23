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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    s = " " + s;
    map<char, int> cnt;
    long long ans = 0;
    for(int i = 1; i <= n; i ++) {
        int lx = i - r - 1;
        int rx = i - l;
        if(lx >= 1) cnt[s[lx]] --;
        if(rx >= 1) cnt[s[rx]] ++;

        // cout << lx << " " << rx << endl;

        ans += cnt[s[i]];
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
    return 0;
}