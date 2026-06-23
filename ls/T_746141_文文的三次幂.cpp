#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N];

void solve()
{
    int n;cin >> n;
    int ans = 0;
    map<ll,int> cnt;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        for(ll x = 3; x <= 2e9; x *= 3) {
            if(cnt.find(x - a[i]) != cnt.end()) ans += cnt[x - a[i]];
        }
        cnt[a[i]] ++;
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
    return 0;
}


