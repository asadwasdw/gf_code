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

int a[N];
int b[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i], a[i] += a[i - 1];
    for(int i = 1; i <= n; i ++) cin >> b[i];

    while(m --) {
        int k ;
        cin >> k;
        priority_queue<int>s;
        int ans = INFll;
        int res = 0;
        for(int i = 1; i <= n; i ++) {
            if(s.size() < k) {
                s.push(b[i]);
                res += b[i];
            }
            else if(s.top() > b[i]) {
                res -= s.top();
                res += b[i];
                s.pop();
                s.push(b[i]);
            }
            if (i >= k)ans = min(ans, res + a[i]);
            // cout << k << " " << i << " " << res << endl;
        }
        cout << ans << endl;
    }





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