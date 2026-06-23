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
    int n;
    cin >> n;
    vector<string> v;

    for(int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        if(s.size() == 1) continue;
        // v.push_back(s);
        for(int j = 0; j < s.size() - 1; j ++) {
            if((j + 1 < s.size() && s[j] > s[j + 1]) || j == s.size() - 1) {
                v.push_back(s.substr(0, j) + s.substr(j + 1));
                // cout << i << " " << j << endl;
                break;
            }
        }
    }

    sort(v.begin(), v.end(),[&](string a, string b){
        return a + b < b + a;
    });

    for(auto t : v) cout << t;
    



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