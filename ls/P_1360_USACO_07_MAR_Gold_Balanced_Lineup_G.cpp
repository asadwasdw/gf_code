#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const ll mod=998244353;
const ll P=99997;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
typedef unsigned long long ull;

struct w{
    ull x;
    int id;
};

struct node{
	vector<w> q[N];
	void clear(){
		for(int i=0;i<P;i++)q[i].clear();
	}
	void insert (ull x, int id){
		ll y=(x % P + P) % P;
		q[y].push_back({x, id});
	}
	ll find(ll x){
		ll y=(x % P + P) % P;
		for(int i=0;i<q[y].size();i++){
			if(q[y][i].x !=  x)continue;
            return q[y][i].id;
		}
		return -1;
	}
}mp2;



ll a[N][35]; 

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll p = 100007;
    mp2.insert(0, 0);

    ll ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        ll x;
        cin >> x;
        for(int j = 0; j < m; j ++) {
            if((x >> j) & 1) a[i][j] = 1;
            a[i][j] += a[i - 1][j];
        }

        ll res = 0;
        for(int j = 1; j < m; j ++) {
            ull l = a[i][j] - a[i][j - 1] ;
            res = res * p + l;
            res %= mod;
        }

        ll l = mp2.find(res);
        if(l != -1)ans = max(ans, i - l);
        mp2.insert(res, i);
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