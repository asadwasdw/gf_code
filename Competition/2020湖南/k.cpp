#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int n;
    while(cin >> n) {

        string s; cin >> s;
        s = " " + s; 

        ll ans = 1;
        ll c = 1;
        for(int i = n - 1; i > 1;i --) {
            if(s[i] == '1') {
                c++;
                ans = ans * (c + i - 1);
            } else {
                ans = ans * (c);
            }
            ans %= mod;
            // cout << i << " : " << ans << endl;
        }
        cout << ans << endl;
    }

    // vector g(n + 1, vector (n + 1, 0));
    // vector<int> cnt(n + 1, 0);
//     for(int i = 1; i <= n; i ++) {
//         if(s[i] == '1') {
//             for(int j = 1; j < i; j ++) {
//                 g[i][j] = g[j][i] = -1;
//                 g[i][i] ++;
//                 g[j][j] ++;
//             }
//         }
//     }

//     for(int i = 1; i <= n; i ++) 
//         for(int j = 1; j <= n; j ++) 
//             cout << g[i][j] << " \n"[j == n];
    
//     for(int i = 2; i < n; i ++) 
//         for(int j = 1; j < n; j ++) 
//             g[1][j] += g[i][j];

//     cout << endl;
//     for(int i = 1; i < n; i ++) 
//         for(int j = 1; j < n; j ++) 
//             cout << g[i][j] << " \n"[j == n - 1];

//    for(int i = 1; i < n; i ++) 
//         for(int j = 2; j < n; j ++) 
//             g[i][j] -= g[i][1];

//     cout << endl;
//     for(int i = 1; i < n; i ++) 
//         for(int j = 1; j < n; j ++) 
//             cout << g[i][j] << " \n"[j == n - 1];

 

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