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
int n,m;
int a[N];


void solve()
{
    string s;
    cin >> s;
    s = " " + s;
    map<string,int>mp;
    for(int i = 1; i < s.size(); i += 2) {
        mp[s.substr(i,2)] ++;
    }
    if(mp["1s"]&&mp["9s"]&&mp["1p"]&&mp["9p"]&&mp["1m"]&&mp["9m"]&&mp["1z"]&&mp["2z"]&&mp["3z"]&&mp["4z"]) {
        cout << "Thirteen Orphans";
    }
    else {
        map<string,int>mp;
        for(int i = 1; i < s.size(); i += 2) {
            mp[s.substr(i,2)] ++;
        }
        bool ky = true;
        for(auto [i,j] : mp) {
            // cout << i << " " << j << endl;
            if(j != 2)ky = false;
        }
        if(ky) cout <<"7 Pairs";
        else cout << "Otherwise";
    }
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