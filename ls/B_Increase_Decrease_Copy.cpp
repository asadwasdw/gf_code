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
int b[N];


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n + 1; i ++) cin >> b[i];
    int ans = 0;
    int ans1 = INF;  
    for(int i = 1; i <= n; i ++) {
        if(a[i] > b[i]) swap(a[i], b[i]);
        ans += b[i] - a[i];
        if(a[i] <= b[n + 1] && b[n + 1] <= b[i]) ans1 = 0;
        else {
            ans1 = min({ans1, abs(a[i] - b[n + 1]),  abs(b[i] - b[n + 1])});
        }
    }
    cout << ans + ans1 + 1 << endl;








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