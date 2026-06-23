#include<bits/stdc++.h>
#define int long long
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
    string s; cin >> s;
    s = " " + s;
    int cnt = 0;
    queue<int> q;
    int ans = 0;
    vector<int>a(n + 1);

    for(int i = n; i >= 1; i --) {
        if(s[i] == '1') q.push(i);
        else {
            ans += i;
            if(q.size())q.pop();
        }
    } 

    int t = (q.size() + 1)/2;
    while(q.size()) {
        if(q.size() <= t) ans += q.front();
        q.pop();
    }
    cout << ans << endl;

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