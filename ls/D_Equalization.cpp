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
#define int long long
string calc(int x) {
    string res;
    while(x) {
        res += (char)(x % 2 + '0');
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
} 

void solve()
{
    string sa, sb;
    int a, b;
    cin >> a >> b;
    sa = calc(a);
    sb = calc(b);
    // cout << sa << " " << sb << endl;
    int i = 0;
    for(i = 0; i < min(sa.size(), sb.size()); i ++) {
        if(sa[i] != sb[i]) break;
    }
    // cout << i << endl;
    a = sa.size() - i, b = sb.size() - i;
    // cout << a << " " << b << endl;
    i = 0;
    ll ans = 0;
    while(a != 0 || b != 0)  {
        i ++;
        if(a > b) swap(a, b);
        if(i == a) {
            a -= i;
            ans += 1ll << i;
        } else if(i == b) {
            b -= i;
            ans += 1ll << i;
        } else if(2 * i < b) {
            b -= i;
            ans += 1ll << i;
        }
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