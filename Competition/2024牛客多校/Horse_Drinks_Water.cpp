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


long double js(int x1, int y1, int x2, int y2) {
    int x = x2 - x1;
    int y = y2 - y1;
    return sqrtl(x*x + y*y);
}

void solve()
{
    int x,y,t1,t2;
    cin >> x >> y >> t1 >> t2;
    cout << min(js(x,y,t1,-t2), js(x, y, -t1,t2)) << endl;
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