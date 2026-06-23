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
//vector<vector<int>>adj(N);
const double eps = 5e-5;

void solve()
{
    double A; cin >> A;
    // a *= 100;
    int a = (int)(A*100);
    if(a == 0) {
        cout << "1" << endl;
        return;
    }

    for(int i = 1; i <= 10000; i ++) {
        for(int j = 1; j <= i; j ++) {
            int t = (double)(j)/i*10000+0.5;
            if(t == a) {
                cout << i;
                return;
            }
        }
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
}