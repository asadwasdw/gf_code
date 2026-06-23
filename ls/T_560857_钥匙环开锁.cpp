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
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s = s + s;

    int ans = 0;

    while(m --) {
        bool ky = false;
        string t;
        cin >> t;
        if(t.size() > n) continue;
        for(int i = 0; i + t.size() < s.size() && !ky; i ++) {
            string t2 = s.substr(i, t.size());
            t2 = t2 + t2;

            for(int j = 0; j + t.size() < t2.size() && !ky; j ++) {
                if(t == t2.substr(j, t.size())) {
                    ky = true;
                }
            }
        }
        if(ky) ans++;
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