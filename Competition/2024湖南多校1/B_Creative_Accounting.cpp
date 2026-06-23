#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n,l,h;
ll a[N];

void solve()
{
    cin >> n >> l >> h;
    for(int i=1; i<=n; ++i)cin >> a[i], a[i] += a[i-1];
    ll mi = INF, mx = -INF;
    for(int len=l; len<=h; ++len){
        
        for(int i=1; i<=len && i<=n; ++i){
            ll sum = 0;
            sum += (i-1 >= 1 && a[i-1] > 0);
            int j;
            for(j=i; j+len-1<=n; j+=len){
                sum += (a[j+len-1] - a[j-1] > 0);
            }
            if(j <= n )sum += (a[n] - a[j-1] > 0);
            mi = min(sum, mi);
            mx = max(sum, mx);

        }
    }
    cout << mi << ' ' << mx << '\n';


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