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
    string s, t;
    cin >> s >> t;
    vector<string> ans;

    for(int i = 0; i < s.size(); i ++) {
        if(s[i] > t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }


    for(int i = s.size(); i >= 0; i --) {
        if(s[i] < t[i]) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    cout << ans.size() << endl;
    for(auto t: ans)cout << t << endl;






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