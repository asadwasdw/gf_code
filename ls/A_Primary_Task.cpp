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
    string s;
    cin >> s;
    bool ky = true;
    if(s.size() < 3 || s.substr(0, 2) != "10" ) {
        ky = false;
        cout << "NO\n";
        return;
    }
    string T = s.substr(2,s.size() - 2);
    int t = 0;
    if(T.size())t = stoi(T);
    // cout << t << endl;
    if(t == 1 || t == 0 || to_string(t) != T) {
        ky = false;
    }
    if(ky) cout << "YES";
    else cout << "NO";
    cout << endl;








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