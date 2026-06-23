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

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    int r = n;
    int ans = 0;
    int l = 0;
    for(int i = 1; i <= n; i ++) {
        if(l == 0 && s[i] == '1') l = i;
        if(s[i] == '1') continue;
        if(l == 0) continue;
        // cout << ans << endl;
        ans += i - l + 1;
        l ++;
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