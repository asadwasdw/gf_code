#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

const ll P=1e5 + 7;
//vector<vector<int>>adj(N);

ll a[N];

map<ll,bool> mp;

struct w{
    ll x, a, b;
};

struct node{
	vector<w> q[N];
	void clear(){
		for(int i=0;i<P;i++)q[i].clear();
	}
	void insert(ll x, ll a, ll b){
		ll y=(x % P + P) % P;
		q[y].push_back({x, a, b});
	}
	bool find(ll x, ll c, ll d){
		ll y=(x % P + P) % P;
		for(int i=0;i<q[y].size();i++){
			if(q[y][i].x !=  x)continue;
            set<int> s;
            s.insert(c);
            s.insert(d);
            s.insert(q[y][i].a);
            s.insert(q[y][i].b);

            if(s.size() == 4) return true;
		}
		return false;
	}
}mp2;


void solve()
{
    // mp.clear();
    mp2.clear();
    int n;
    cin >> n;
    if(n == 0) {
        exit(0);
    }

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }


    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < i; j ++) {
            mp2.insert(a[i] + a[j], i, j);
        }
    }

    ll ans = -INFll;

    for(int i = 1; i <= n; i ++) {
        bool ky = false;
        for(int j = 1; j <= n; j ++) {
            if(mp2.find(a[i] - a[j], j, i)) ky = true;
        }
        if(ky) ans = max(ans, a[i]);
    }

    if(ans == -INFll) cout << "No Solution\n";
    else cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    // cin>>t;
    for(int i=1;1;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}