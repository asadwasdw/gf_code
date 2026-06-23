#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{

    int n;cin >> n;
    vector< map<string, int> > mp(6);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            string s;cin >> s;
            mp[j][s]++;
        }
    }
    int m;cin >> m;
    vector<vector<string>> s(6);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string t;cin >> t;
        int id; cin >> id;
        s[id].push_back(t);
        if (mp[id][t]) cnt++;
    }

    for (int i = 1; i <= 5; i++) cnt = min(cnt, (int)s[i].size());

    cout << cnt << '\n';    







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}