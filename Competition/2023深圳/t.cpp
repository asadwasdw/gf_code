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
    int k; cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    int cntT = 0, cntF = 0, r = 1, ans = 0;
    for(int l = 1; l <= n; l ++) {
        while(r <= n) {
            int t = 0, f = 0;
            if(s[r] == 'T') t ++;
            else f ++;
            if(min(cntT + t, cntF + f) <= k) {
                r ++, cntT += t, cntF += f;
            }
            else break;
        }
        ans = max(r - l, ans);
        // cout << l << " " << r << endl;
        if(s[l] == 'T') cntT --;
        else cntF --;
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