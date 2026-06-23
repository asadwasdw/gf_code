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


void solve()
{
    int n, k;
    cin >> n >> k;
    int len = 0;
    if(n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    while(1) {
        if(k - len < 1 || k + len > n) break;
        int l = k - 1 - len ;
        int r = n - k - len;
        // cout << l << " " << r << endl;
        if(l%2 && r%2) {
            cout << 3 << endl;
            cout << 1 << " " << l + 1 << " " << n - r + 1 << endl;
            return;
        }
        len ++;
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