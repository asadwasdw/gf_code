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


void solve()
{
    int n,m,a,b;

    while(cin >> n >> m >> a >> b) {
        bool ky = true;
        if(n * m % 2) ky = false;
        if(!b && min(n,m) != 1) ky = false;
        if(!a && min(n,m) == 1 && max(n,m) > 2) ky = false;
        cout << n << " " << m << " " << a << " " << b << " ";
        if(ky) cout << "Yes\n";
        else cout << "No\n"; 
    }







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}