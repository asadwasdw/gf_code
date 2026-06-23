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
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    vector<PII> v;
    int cnt = 0;
    for(int i = 0; i < s.size();  i ++ ) {
        cnt++;
        if( i == s.size() - 1 || s[i] != s[i + 1]) {
            v.push_back({s[i]-'0', cnt});
            cnt = 0;
        } 
    }
    int ans = 0;
    for(int i = 0; i < v.size(); i ++) {
        if(v[i].first == 1) {
            k -- ;
            if(k == 0) {
                swap(v[i], v[i - 1]);
                break;
            }
        }
    }

    for(auto [x, y] : v) {
        while(y -- ) {
            cout << x;
        }
    }






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