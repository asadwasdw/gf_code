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
    string s;
    cin >> n;
    int res = 0;
    while(n--){
        cin >> s;
        if(s.size() == 5 && s[2] == s[4]){
            set<char> p;
            for(int i=0; i<4; ++i)p.insert(s[i]);
            if(p.size() == 4)++res;
        }
    }
    cout << res;






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