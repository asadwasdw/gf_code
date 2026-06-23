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
    vector a(n + 1, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];


    int m; cin >> m;
    while(m --) {
        bool ky = true;
        string s; cin >> s;
        if(s.size() != n) ky = false;
        map<char,int> mp; 
        map<int ,char> mp2; 
        for(int i = 0; ky && i < s.size(); i ++) {
            if(mp.count(s[i]) ) {
                if(mp[s[i]] != a[i]) ky = false;
            } else {
                mp[s[i]] = a[i];
            }


            if(mp2.count(a[i])) {
                 if(mp2[a[i]] != s[i]) ky = false;
            } else {
                mp2[a[i]] = s[i];
            }
        }
        if(ky) cout << "YES\n";
        else cout << "NO\n";
    }



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