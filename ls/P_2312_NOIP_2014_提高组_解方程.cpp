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

ll read(){
	char c=getchar();
	ll f=1,x=0;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		x=(x * 10 + c-'0') % mod; // 读入的时候就取模
		c=getchar();
	}
	return x*f;
}

ll a[N];


void solve()
{
    ll n = read();
    ll m = read();
    for(int i = 0; i <= n; i ++) {
        a[i] = read();
    }

    vector<int> v;
    for(int i = 1; i <= m; i ++)  {
        ll ans = a[n];
        for(ll j = n - 1; j >= 0; j --) {
            ans = (ans * i % mod + a[j]) % mod;
        }
        if(ans == 0) 
            v.push_back(i);
    }
    cout << v.size() << endl;
    for(auto t : v) cout << t << endl;






}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}