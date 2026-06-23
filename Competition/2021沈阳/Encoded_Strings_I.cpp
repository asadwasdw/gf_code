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
    int n; cin >> n;
    string s; cin >> s;
    auto calc = [&](string s) -> string {
        int n = s.size();
        set<char> st;
        map<char,int> num;

        for(int i = s.size() - 1; ~i; i --) {
            if(num.count(s[i]) == 0) {
                num[s[i]] = st.size();
            }
            st.insert(s[i]);
        }
        string res;
        for(int i = 0; i < n; i ++) {
            char t = (char)('a' + num[s[i]]);
            res += t;
        }
        return res;
    };
    string ans = "";
    for(int i = 1; i <= n; i ++) {
        string t = calc(s.substr(0, i));
        if(t > ans) swap(ans, t);
    }

    cout << ans;

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