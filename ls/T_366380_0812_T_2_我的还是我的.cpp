#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const ll mod=998244353;
const ll P=1000003;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
typedef unsigned long long ull;
ll mp[N];

ll a[N];
ll p = 100559;
ll h[N];
ll s[N];
map<int,int> cnt;
signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        a[i] = rand();
        h[i] = h[i - 1] ^ a[i];
    }
    cnt[0] = 1;
    int x;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        s[i] = s[i - 1] ^ a[x];            
    }
    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += cnt[s[i] ^ h[i]];
        cnt[s[i] ^ h[i]] ++;
    }
    cout << ans << endl;
    
    return 0;
}