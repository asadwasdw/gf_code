#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
 int num[50][2];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;

    // for(int l = 1; l <= n; l ++) {
    //     for(int r = l; r <= n; r ++) {
    //             for(int i = l; i <= r; i ++) {
    //                 for(int j = l; j <= r; j ++) {
    //                     ans += a[i] ^ a[j];
    //                 }
    //             }
    //     }
    // }
    // cout << ans << endl;
    
    int ans2 = 0;
    for(int l = n; l >= 1; l -- ) {
        int t = 0;

        for(int k = 0; k < 32 ; k ++) {
            int t2 = (a[l] >> k) & 1;
            t += (1 << k) * num[k][t2 ^ 1];
            num[k][t2] += (n - l + 1);
            num[k][t2] %= mod;
            t %= mod;
        }


        t *= l;
        t %= mod;
        ans2 += t * 2;
        ans2 %= mod;
    }



    cout << ans2   << endl;







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