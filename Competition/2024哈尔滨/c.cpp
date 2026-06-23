#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    vector<string> ans;
    char be = ' ';
    int last;
    for(int i = 1; i <= n; i ++) {
        char s;
        int len;
        cin >> s >> len;
        if(i == 1) {
            be = s;
        } else {
            if(last == 'N') {
                if(s == 'W') ans.push_back("L");
                if(s == 'E') ans.push_back("R");
            }

            if(last == 'S') {
                if(s == 'E') ans.push_back("L");
                if(s == 'W') ans.push_back("R");
            }

            if(last == 'E') {
                if(s == 'N') ans.push_back("L");
                if(s == 'S') ans.push_back("R");
            }

            
            if(last == 'W') {
                if(s == 'S') ans.push_back("L");
                if(s == 'N') ans.push_back("R");
            }
        }
        last = s;
        ans.push_back("Z " + to_string(len));
    }

    cout << ans.size() << " " << be << endl;
    for(auto t : ans) cout << t << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}