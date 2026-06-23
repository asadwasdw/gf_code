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

string s[N];
bool cmp(string a, string b) {
    return a + b > b + a;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
    }

    sort(s + 1, s + n + 1, cmp);

    for(int i = 1; i <= n; i ++) {
        cout << s[i];
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
    return 0;
}