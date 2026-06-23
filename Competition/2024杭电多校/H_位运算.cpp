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


void solve()
{
    // cout << pow(12, 15) << endl;
    int a = 0, b = 0;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++ ) {
                for(int z = 0; z < 2; z ++) {
                    if((((i&j)^k)|z) == 1) a++;
                    else b ++;
                }
            }
        }
    }
    // cout << a << " " << b << endl;
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for(int i = 0; i < k; i ++) {
        if((n >> i) & 1) ans *= a;
        else ans *= b;
    }
    cout << ans << endl;








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