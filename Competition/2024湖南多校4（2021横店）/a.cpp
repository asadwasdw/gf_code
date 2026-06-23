#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define double long double

const double PI = acos(-1.0);

//vector<vector<int>>edg(N);


struct Node{
    int x,y,z;
}node[N];

double js(int i,int j) {
    double x = node[i].x - node[j].x;
    double y = node[i].y - node[j].y;
    double z = node[i].z - node[j].z;
    return sqrtf(x*x + y*y + z*z);
}

void solve()
{
    int n, r;
    cin >> n >> r;
    for(int i = 1; i <= n; i ++) {
        cin >> node[i].x >> node[i].y >> node[i].z;
    }
    node[0] = node[n];
    node[n + 1] = node[1];
    double ans = 0;

    for(int i = 1; i <= n; i ++) {
        ans += 4.0 * PI * r * r * r / 3;
        double d = js(i,i - 1);
        ans -= 2.0 * PI * (r - d/2) * (r - d/2) * (2*r + d/2) / 3  ;
    }
    cout << ans << endl;


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(9) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}