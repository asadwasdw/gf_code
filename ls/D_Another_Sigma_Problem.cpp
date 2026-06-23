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
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int sum = 0;
    int ans = 0;
    for(int i = n; i >= 1; i --) {
        int num = 0;
        ans += a[i] * sum;
        ans += (i - 1) * a[i];
        while(a[i]) {
            a[i] /= 10;
            num++;
        }
        sum += pow(10,num);
        sum %= mod;
        ans %= mod;
    }
    cout << ans % mod << endl;







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