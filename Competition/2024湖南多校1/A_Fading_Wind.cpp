#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int h,k,v,s;
    cin >> h >> k >> v >> s;

    int ans = 0;
    int cnt = 10;
    while(h > 0 && v > 0) {
        // cout << h << " " << v <<endl;
        v += s;
        v -= max(1ll,v/10);
        if(v >= k) h++;
        else h--;
        if(h == 0) v = 0;

        if(v<=0) {
            h=0,v=0;
            break;
        }
        ans += v;
        if(s > 0) s --;   
    }
    cout << ans << endl;







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