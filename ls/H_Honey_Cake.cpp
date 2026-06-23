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


void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    int ga = __gcd(a, n); n /= ga;
    int gb = __gcd(b, n); n /= gb;
    int gc = __gcd(c, n); n /= gc;

    if(n == 1) {
        cout << ga - 1 << " " << gb - 1 << " " << gc - 1 << endl;
    } else {
        cout << "-1\n";
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