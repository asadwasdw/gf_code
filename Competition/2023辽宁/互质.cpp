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
    int l = (n + 3) / 4;
    int r = n / 2;
    // cout << l << " " << r << endl;

    for(int i = l; i <= min(l + 100,r); i ++) {
        if(__gcd(i, n)  == 1) {
            cout << i << endl;
            return;
        }
    }
    cout << "-1" << endl;

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