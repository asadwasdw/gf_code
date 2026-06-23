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
int a[N];

void solve()
{
    priority_queue<int> q;
    int n;
    cin >> n;
    int ans = 0;
    multiset<int> s;

    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        int cnt = x/5;
        x -= cnt * 5;
        ans += cnt * 3;
        while(x > 0) {
            if(ans % 3 == 2) x -= 3, ans ++;
            else ans ++, x -= 1;
        }
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