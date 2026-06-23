#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

map<char,int> mp;

void solve()
{
    for(int i = 0; i < 5; i ++) {
        int x; cin >> x;
        char t = 'A' + i;
        mp[t] = x;
    }

    vector<PII> p;

    for(int st = 1; st < 32; st ++) {
        string s;
        int w = 0;
        for(int i = 0; i < 5; i ++) {
            if((st >> i) & 1) {
                char t = 'A' + i;
                w += mp[t];
                s += t; 
            }
        }
        p.push_back({s, w});
    }

    sort(p.begin(), p.end(),[&](PII a, PII b){
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    for(auto [s, w] : p) cout << s << endl;








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