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
    int mx = 0;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        mx = max(mx, x);
    }
    while(m --) {
        char x; int l, r; cin >> x >> l >> r;
        if(l <= mx && mx <= r) {
            if(x == '+') mx ++; 
            else mx --;
        } 
        cout << mx << " \n"[m == 0];
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