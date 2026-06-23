#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define double long double
#define endl "\n" 
const double eps = 1e-12;
//vector<vector<int>>edg(N);
int n,m;
int a[N];

int h, r, da, db;

double js(double x) {
    double xa = x/2;
    double xb = (h - x)/2;
    double xab = xa + xb;
    double wa = x * r * r * da;
    double wb = (h - x) * r * r * db;
    // cout << x << " " << xa + xab/(wa + wb) * wb << endl;
    return xa + xab/(wa + wb) * wb;
}

void solve()
{
    cin >> h >> r >> db >> da;
    double L = 0, R = h;
    while((R - L) >= eps)  {
        double k = (R - L)/3;
        double mid1 = L + k;
        double mid2 = L + k + k;
        if(js(mid1) < js(mid2)) R = mid2;
        else L = mid1;
    }
    cout << L << endl;
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