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
    string s; cin >> s; s = " " + s;

    {
        set<int> st;
        for(int i = 2; i <= n; i ++) {
            if(s[i] == '.') continue;
            st.insert(s[i]);
        }
        if(st.size() < 2 && s[1] != 'p') {
            cout << "YES\n";
            return;
        } 
    }

    {
        set<int> st;
        for(int i = 1; i < n; i ++) {
            if(s[i] == '.') continue;
            st.insert(s[i]);
        }
        if(st.size() < 2 && s[n] != 's') {
            cout << "YES\n";
            return;
        } 
    }

    cout << "NO\n";






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