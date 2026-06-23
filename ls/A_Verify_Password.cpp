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
    map<char,int> mp;
    for(int i = 0; i <= 9; i ++) {
        mp[(char)('0' + i)] = i;
    }

    for(int i = 0; i <26; i ++) {
        mp[(char)('a' + i)] = i + 10;
    }

    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i < n; i ++){
        if(mp[s[i]] < mp[s[i - 1]]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";


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