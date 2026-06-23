#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


bool st[N];
int pri[N], cnt;

void qie_p(int n) {
    for(int i = 2; i <= n; i ++) {
        if(!st[i]) pri[cnt ++] = i;
        for(int j = 0; i * pri[j] <= n; j ++) {
            st[i * pri[j]] = true;
            if(i % pri[j] == 0) break;
        }
    }
}


void solve()
{
    qie_p(N - 1);

    ll l, r;
    cin >> l >> r;

    int ans = 1;
    for(int i = 0; i < cnt; i ++) {
        ll t = pri[i];
        while(t * pri[i] <= r) {
            t *= pri[i];
            if(t >= l + 1) {
                ans ++;
                // cout << t << endl;
            }
        }
    }

    unordered_map<ll,int> mp;

    for(int i = 0; i < cnt && 1ll * pri[i] * pri[i] <= r; i ++) {
        ll p = pri[i];
        ll st = ((l + 1) + p - 1) / p * p;

        st = max(st, 2ll * p);

        while(st <= r) {
            mp[st] = true;
            // cout << st << endl;
            st += p;
        }
    } 

    // for(auto [x, y] : mp) cout << x << endl;

    ans += r - l - mp.size();
    cout << ans << endl;



    // unordered_map<ll, bool>mp;//标记非素数
	// for(int i = 1; i <= cnt && pri[i] <= r / pri[i]; i++){//标记[l+1,r]里的非素数
	// 	ll p = pri[i];
	// 	ll st = (l + p - 1) / p * p;
	// 	st = max(st, p*p);
	// 	for(ll j = st; j <= r; j += p){
	// 		mp[j] = 1;
	// 	}
	// }
	// res += (r - l + 1) - mp.size();







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