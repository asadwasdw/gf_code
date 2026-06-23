#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

using i64 = long long;

void solve()
{
    string s; cin >> s;
    i64 n = s.size() / 2;
    i64 cnt = 0;
    vector<int> st;
    
    i64 ans = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ')') {
            cnt++;
            int la = st.back();
            st.pop_back();
            if (la != i - 1) {
                ans = (n - cnt + 1) % mod * ans % mod;
            }
        } else {
            st.push_back(i);
        }
    }
    cout << ans << '\n';





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