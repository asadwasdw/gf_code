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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    

    if(n % 2 == 0) {
        ll t = 1;
        while(t <= l) t *= 2;
        
        if(t <= r && n >= 4) {
            if(k <= n - 2) cout << l << endl;
            else cout << t << endl;
        } else {
            cout << "-1" << endl;
        }
    } else {
        cout << l << endl;
    }




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