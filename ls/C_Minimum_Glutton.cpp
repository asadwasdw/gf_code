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
PII a[N];

void solve()
{
    int x, y;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first ;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    int ans = n;

    {
        sort(a + 1, a + n + 1, [&](PII a, PII b){
            return a.first > b.first;
        });
        int t = 0;

        for(int i = 1; i <= n; i ++) {
            t += a[i].first;
            if(t > x) {
                ans = min(ans, i);
            }
        }
    }

    {
            
        sort(a + 1, a + n + 1, [&](PII a, PII b){
            return a.second > b.second;
        });
        int t = 0;

        for(int i = 1; i <= n; i ++) {
            t += a[i].second;
            if(t > y) {
                ans = min(ans, i);
            }
        }
    }

    cout << ans;








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