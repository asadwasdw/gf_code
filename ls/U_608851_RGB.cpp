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
    int n;
    cin >> n;
    string s; cin >> s;
    s = " " + s;
    map<char,int> cnt;
    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            if(s[i] == s[j]) continue;
            for(auto [c, num] : cnt) {
                if(c != s[i] && c != s[j]) ans += num;
            }
            int l = 2 * i - j;
            if(l >= 1 && s[l] != s[i] && s[l] != s[j]) ans --;
        }

        cnt[s[i]] ++;
        // cout << i << " " << ans << endl;
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